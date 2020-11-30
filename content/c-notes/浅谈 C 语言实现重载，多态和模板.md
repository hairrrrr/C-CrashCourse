### C 语言实现重载，多态和模板

#### 为什么 C 语言不支持重载

这和 C 和 C++ 的函数名称修饰有关。编译（并汇编）一个 C 和 Cpp 程序，使用 `objdump -dS `命令查看 ELF 格式文件发现：

```
[root@SuperhandsomeChuan ~]# objdump -dS test.o

0000000000000000 <main>:

[root@SuperhandsomeChuan ~]# objdump -dS testcpp.o

0000000000000000 <_Z3sumii>:

0000000000000014 <_Z3sumdd>:
```

`gcc` 编译器下，C 程序的函数名没有变化，但是 Cpp 程序的函数名称有了参数相关的后缀，这使得重载的 sum 函数底层的函数名称不同，编译器可以区分。

####  C 语言实现重载

| 函数                    | 描述                                                         |
| ----------------------- | ------------------------------------------------------------ |
| col 3 is                | right-aligned                                                |
| va_list arg_ptr         | 定义一个可变参数列表指针                                     |
| va_start(arg_ptr, argN) | 让arg_ptr指向参数argN                                        |
| va_arg(arg_ptr, type)   | 返回类型为type的参数指针,并指向下一个参数                    |
| va_copy(dest, src)      | 拷贝参数列表指针,src->dest,                                  |
| va_end(arg_ptr)         | 清空参数列表，并置参数指针arg_ptr无效。每个va_start()必须与一个va_end()对应 |

参考文章：http://locklessinc.com/articles/overloading/

```c
#include<stdio.h>
#include<stdarg.h>

void va_overload2(int p1, int p2)
{
  printf("va_overload2 %d %d\n", p1, p2);
}

void va_overload3(int p1, int p2, int p3)
{
  printf("va_overload3 %d %d %d\n", p1, p2, p3);
}

static void va_overload(int p1, int p2, ...)
{
  if(p2 == 7)
  {
    va_list v;
    va_start(v, p2);
    
    int p3 = va_arg(v, int); 
    va_end(v);
    va_overload3(p1, p2, p3);

    return;
  }
  va_overload2(p1, p2);
}

int main(void)
{
  va_overload(1, 2);
  va_overload(1, 7, 4);

  return 0;
}
//输出：
va_overload2 1 2
va_overload3 1 7 4
```

上面的代码，我们可以解析函数参数，然后选择调用 `va_overload2()` 或 `va_overload3()` 。POSIX 的 `open()` 函数在你的机器上也许有着类似的实现方式。

另一种 `va_args`常见的用法是接受数量没有限制参数，没有直接的可接受数量的说明符。通过 NULL 来结束参数列表，我们可以解析任意对我们函数的输入。

```c
#include<stdio.h>
#include<stdarg.h>

static void print_nt_strings(const char* s, ...)
{
  va_list v;
  va_start(v, s);

  /* Stop on NULL */ 
  while(s)
  {
    printf("%s\n", s);
    /* Grab next parameter */ 
    s = va_arg(v, const char*);
  }

  va_end(v);
}

int main(void)
{

  print_nt_strings("Hello", "World", "brrrrr~~~", NULL);

  return 0;
}
// 输出
Hello
World
brrrrr~~~
```



上面的函数将会打印传递给他的 C 字符串。无论最后一个指针是否是 NULL 。这里的问题是需要记得最后在参数列表后加上 NULL 。如果它丢掉了，上面的函数将会把栈上的值当作 `const char*` 指针然后尝试将其打印出来。这回引发未定义行为，这可能会使这个程序崩溃。

一种解决办法是明确的说明有多少参数存在，将最后的参数 NULL 删除。 让用户人为的确定个数是不便且易错的。

*这段我感觉自己翻译的不是很好，有兴趣可以自己去看原文*

```c
#include<stdio.h>
#include<stdarg.h>

static void print_nt_strings(int n, ...)
{
  va_list v;
  va_start(v, n);
  int i;
  for(i = 0; i < n; i++)
  {
    const char* s = va_arg(v, const char*);

    printf("%s\n", s);
  }

  va_end(v);
}

int main(void)
{

  print_nt_strings(3, "Hello", "World", "brrr~~");
  print_nt_strings(2, "Gooble", "World");

  return 0;
}
//输出
Hello
World
brrr~~
Gooble
World
```



####  C 语言实现多态

下面程序的本质就是 C++ 多态的实现

```c
#include<stdio.h>

typedef void (*Func1)();
typedef void (*Func2)();

// 虚函数表
typedef struct VFunTable
{
  Func1 eat;
  Func2 sleep;
}VFunTable;

// 基类
typedef struct base 
{
  VFunTable vptr; 
  const char kind[20];
}Base;

// 派生类
typedef struct derive 
{
 Base base; 
 const char kind[20];
}Derive;

void base_eat()
{
  printf("base eat\n");
}

void base_sleep()
{
  printf("base sleep\n");
}

void derive_eat()
{
  printf("derive eat\n");
}

void derive_sleep()
{
  printf("derive sleep\n");
}

void init(Base* b, Derive* d)
{
  b->vptr.eat   = base_eat;
  b->vptr.sleep = base_sleep; 

  d->base.vptr.eat   = derive_eat;
  d->base.vptr.sleep = derive_sleep; 
}

int main(void)
{
  struct base b;
  Derive d;
  init(&b, &d);

  Base* pb = &b;
  Base* pb2 = (Base*)&d;

  pb->vptr.eat();
  pb2->vptr.eat();

  return 0;
}
//输出
base eat
derive eat
```



####  C 语言实现模板

`##` 运算符可以将两个表达式“拼”起来

```c
#include<stdio.h>

#define GENERATE(type)                 \
        type type##_max(type A, type B) \
        {                              \
          return (A > B ? A : B);      \
        }                              \

GENERATE(int);
GENERATE(double);

int main(void)
{

  printf("%d\n", int_max(3, 5));
  printf("%f\n", double_max(3.0, 5.0));

  return 0;
}
```

看一下预处理后的代码：

```c
int int_max(int A, int B) { return (A > B ? A : B); };
double double_max(double A, double B) { return (A > B ? A : B); };

int main(void)
{

  printf("%d\n", int_max(3, 5));
  printf("%f\n", double_max(3.0, 5.0));

  return 0;
}
```

参考资料：

《C 语言程序设计 —— 现代方法》

http://locklessinc.com/articles/overloading/

https://blog.csdn.net/gatieme/article/details/50921577

https://www.cnblogs.com/qingergege/p/9594432.html
