### 6.指针和数组笔试题

环境：**32 位机器**

#### 第一组

```c
int a[] = {1,2,3,4};
printf("%d\n",sizeof(a));
printf("%d\n",sizeof(a+0));
printf("%d\n",sizeof(*a));
printf("%d\n",sizeof(a+1));
printf("%d\n",sizeof(a[1]));
printf("%d\n",sizeof(&a));
printf("%d\n",sizeof(*&a));
printf("%d\n",sizeof(&a+1));
printf("%d\n",sizeof(&a[0]));
printf("%d\n",sizeof(&a[0]+1));
```

答案：

```c
printf("%d\n",sizeof(a));// 16
printf("%d\n",sizeof(a+0));// 4 (a + 0 这个操作使得编译器将 a 看为指针)
printf("%d\n",sizeof(*a));// 4
printf("%d\n",sizeof(a+1));// 4
printf("%d\n",sizeof(a[1]));// 4
printf("%d\n",sizeof(&a));// 4
printf("%d\n",sizeof(*&a));// 16 (&a 是数组指针。再次用 * 解引用，是从这个地址开始取 int(*)[4] 类型对应的字节数)
printf("%d\n",sizeof(&a+1));// 4 (&a 得到的是 int(*)[4] 类型的指针，只要是指针大小就是 4)
printf("%d\n",sizeof(&a[0]));// 4
printf("%d\n",sizeof(&a[0]+1));// 4
```

#### 第二组

```c
char arr[] = {'a','b','c','d','e','f'};
printf("%d\n", sizeof(arr));
printf("%d\n", sizeof(arr+0));
printf("%d\n", sizeof(*arr));
printf("%d\n", sizeof(arr[1]));
printf("%d\n", sizeof(&arr));
printf("%d\n", sizeof(&arr+1));
printf("%d\n", sizeof(&arr[0]+1));

printf("%d\n", strlen(arr));
printf("%d\n", strlen(arr+0));
printf("%d\n", strlen(*arr));
printf("%d\n", strlen(arr[1]));
printf("%d\n", strlen(&arr));
printf("%d\n", strlen(&arr+1));
printf("%d\n", strlen(&arr[0]+1));
```

答案：

```c
printf("%d\n", sizeof(arr));// 6
printf("%d\n", sizeof(arr+0));// 4
printf("%d\n", sizeof(*arr));// 1
printf("%d\n", sizeof(arr[1]));// 1
printf("%d\n", sizeof(&arr));// 4 (char (*)[6] 类型的指针)
printf("%d\n", sizeof(&arr+1));// 4
printf("%d\n", sizeof(&arr[0]+1));//4

printf("%d\n", strlen(arr));// 未定义 (arr 字符数组没有 '\0'，有可能会出现一个随机值，程序也有可能会崩溃。)
printf("%d\n", strlen(arr+0));// 未定义
printf("%d\n", strlen(*arr)); // 错误的参数类型 (strlen 要的是 char* 类型，但是 *arr 是 char类型。*arr 是字符 a，也就是 97，编译器有可能将 97 当成一个 16 进制的地址。所以，这样的代码一定是不对的)
printf("%d\n", strlen(arr[1]));//同上
printf("%d\n", strlen(&arr));// 未定义
printf("%d\n", strlen(&arr+1)); // 未定义
printf("%d\n", strlen(&arr[0]+1));// 未定义
```

#### 第三组

```c
char arr[] = "abcdef";
printf("%d\n", sizeof(arr));
printf("%d\n", sizeof(arr+0));
printf("%d\n", sizeof(*arr));
printf("%d\n", sizeof(arr[1]));
printf("%d\n", sizeof(&arr));
printf("%d\n", sizeof(&arr+1));
printf("%d\n", sizeof(&arr[0]+1));

printf("%d\n", strlen(arr));
printf("%d\n", strlen(arr+0));
printf("%d\n", strlen(*arr));
printf("%d\n", strlen(arr[1]));
printf("%d\n", strlen(&arr));
printf("%d\n", strlen(&arr+1));
printf("%d\n", strlen(&arr[0]+1));
```

答案：

```c
char arr[] = "abcdef";
printf("%d\n", sizeof(arr));//7
printf("%d\n", sizeof(arr+0));//7
printf("%d\n", sizeof(*arr));//1
printf("%d\n", sizeof(arr[1]));//1
printf("%d\n", sizeof(&arr));//4 (char (*)[7])
printf("%d\n", sizeof(&arr+1));//4 (char (*)[7])
printf("%d\n", sizeof(&arr[0]+1));//4 (char*)

printf("%d\n", strlen(arr));// 6
printf("%d\n", strlen(arr+0));// 6
printf("%d\n", strlen(*arr));// 错误的参数类型
printf("%d\n", strlen(arr[1]));// 同上
printf("%d\n", strlen(&arr));// 6 (&arr 的类型是 char (*)[7] 与 char* 类型不一致，但是 &arr 与 arr 是相同的，所以恰巧能得出正确结果，但是这是错误的写法。)
printf("%d\n", strlen(&arr+1)); // 未定义 (&arr + 1,跳过了整个数组，访问数组后面的空间，非法内存访问)
printf("%d\n", strlen(&arr[0]+1)); // 5 (&arr[0] -> char* ,加以跳过一个数组元素)
```

#### 第四组

```c
char *p = "abcdef";
printf("%d\n", sizeof(p));
printf("%d\n", sizeof(p+1));
printf("%d\n", sizeof(*p));
printf("%d\n", sizeof(p[0]));
printf("%d\n", sizeof(&p));
printf("%d\n", sizeof(&p+1));
printf("%d\n", sizeof(&p[0]+1));

printf("%d\n", strlen(p));
printf("%d\n", strlen(p+1));
printf("%d\n", strlen(*p));
printf("%d\n", strlen(p[0]));
printf("%d\n", strlen(&p));
printf("%d\n", strlen(&p+1));
printf("%d\n", strlen(&p[0]+1));
```

答案：

```c
char *p = "abcdef";
printf("%d\n", sizeof(p));// 4
printf("%d\n", sizeof(p+1));// 4
printf("%d\n", sizeof(*p));// 1
printf("%d\n", sizeof(p[0]));// 1
printf("%d\n", sizeof(&p));// 4 (char**)
printf("%d\n", sizeof(&p+1));// 4 (char**)
printf("%d\n", sizeof(&p[0]+1));// 4 

printf("%d\n", strlen(p));// 6
printf("%d\n", strlen(p+1));// 5
printf("%d\n", strlen(*p));// 错误的参数类型 
printf("%d\n", strlen(p[0]));// 错误的参数类型
printf("%d\n", strlen(&p));// 同上 (&p 的类型是 char**，将char** 强转成的 char* 并不是一个字符串) 
printf("%d\n", strlen(&p+1));// 未定义
printf("%d\n", strlen(&p[0]+1));// 5 (对于 &p[0] 来说，p 先与 [] 结合)
```



> 指针为什么也可以用 `[]`运算符？
>
> 对于指针 int* p = "abc";
>
> `p[1]` 等价于 `*(p + 1)`
>
> 这是因为数组很多时候可以隐式转换成指针。



重点注意：`printf("%d\n", strlen(&p));`

`&p`的类型是 `char**`,但是C语言会将其隐式类型转换成 `char*`，但是 strlen 访问的是地址p的内存空间，那这其实是未定义行为。



#### 第五组

```c
int a[3][4] = {0};
printf("%d\n",sizeof(a));
printf("%d\n",sizeof(a[0][0]));
printf("%d\n",sizeof(a[0]));
printf("%d\n",sizeof(a[0]+1));
printf("%d\n",sizeof(*(a[0]+1)));
printf("%d\n",sizeof(a+1));
printf("%d\n",sizeof(*(a+1)));
printf("%d\n",sizeof(&a[0]+1));
printf("%d\n",sizeof(*(&a[0]+1)));
printf("%d\n",sizeof(*a));
printf("%d\n",sizeof(a[3]));
```

答案：

```c
int a[3][4] = {0};
//所谓二维数组本质是一维数组。里面的每个元素又是一个一维数组。
//本例是一个长度为 3 的一维数组，每个元素又是长度为 4 的一维数组。(VS 中可以用调试来测试)
printf("%d\n",sizeof(a));// 48
printf("%d\n",sizeof(a[0][0]));// 4
printf("%d\n",sizeof(a[0]));// 16 (a[0] 的类型是 int[4])
printf("%d\n",sizeof(a[0]+1));// 4 (a[0]->int[4]相当于一个一维数组，a[0] + 1 隐式转换为指针 int*)
printf("%d\n",sizeof(*(a[0]+1)));// 4 (a[0] + 1 -> a[0][1])
printf("%d\n",sizeof(a+1));// 4
printf("%d\n",sizeof(*(a+1)));// 4
printf("%d\n",sizeof(&a[0]+1));// 4 (a[0] -> int[4],&a[0] -> int (*)[4],再加1还是数组指针)
printf("%d\n",sizeof(*(&a[0]+1)));// 16 (int (*)[4] 解引用变为 int[4])
printf("%d\n",sizeof(*a));// 16 (*a -> *(a + 0) -> a[0])
printf("%d\n",sizeof(a[3]));// 16
```

重点注意：

`printf("%d\n",sizeof(a[0]+1))`

`printf("%d\n",sizeof(&a[0]+1))`

a[0] 与 &a[0] 的差异比较：

```c
	int a[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{5, 10, 11, 12},
	};

	printf("%d\n", *(a[0] + 1));// 2
	printf("%d\n", **(&a[0] + 1));//5
```



`printf("%d\n",sizeof(*(&a[0]+1)));`

我们来一步一步分析：

`a[0] -> int[4] ; &a[0] -> int (\*)[4] ; &a[0] + 1 -> int (\*)[4] ; *(&a[0] + 1) -> int[4]`



`printf("%d\n",sizeof(a[3]))`

`sizeof`是一个运算符，并不是函数。它在预编译时期替换。而我们说的“数组下标访问越界”前提条件是 **内存**访问越界，这个时期是程序运行时。a[3] 就是 int[4] 类型，所以就是 16。哪怕你写 a[100]都可以。

`printf("%d\n", 16)`是程序运行时执行的语句。

#### 关于 const

```c
int num;
const int* p = &num;
int const* p = &num;// 这样的写法不科学，int* 应该当成一个整体，不过它的含义与上面的相同。
int* const p = &num;
```

对于第一种写法，*p 是不能改变的；对于第三种写法，地址 p 是不能被改变的。



### 7. 指针笔试题

#### Ⅰ

```c
int main(void)
{
int a[5] = { 1, 2, 3, 4, 5 };
int *ptr = (int *)(&a + 1);
printf( "%d,%d", *(a + 1), *(ptr - 1));
return 0;
}
```



`a + 1`：a 隐式转换成 指针，指向 首地址后移 4 个字节。（a 隐式转换后是 int* 类型，它指向的 int 大小是 4 个字节，所以后移 4 个字节）

`&a` 的类型是 `int(*)[5]` ,所以 `&a + 1` 后移 int[5] 的长度



所以最后输出的是：2，5

#### Ⅱ

```c
//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
int Num;
char *pcName;
short sDate;
char cha[2];
short sBa[4];
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
int main(void)
{
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	
    return 0;
}
```



`p + 0x1` p 加十六进制的 1，p 所指向的结构体大小是 20，所以 p 会增加 20 。但是注意 `%p` 输出的是 16 进制的地址，所以输出的是 0x100014

`(unsigned long)p + 0x1` p 被强转成了一个数，所以输出的就是 0x100001

`(unsigned int*)p + 0x1` p 被强转成了一个 int* 类型的指针，所以输出的是 0x100004

#### Ⅲ

```c
int main(void)
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf( "%x,%x", ptr1[-1], *ptr2);
	
    return 0;
}
```



`ptr1[-1]`: 前面我们说过，这个操作相当于 `*(ptr1 - 1)`

`(int)a + 1` 是将 a 先强转为 int 然后再加 1，所以 a 仅仅增加了 1 个字节

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200306012537936.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)

#### Ⅳ

```c
#include <stdio.h>
int main(void)
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	p = a[0];	
	printf( "%d", p[0]);
	
    return 0;
}
```



p[0] -> a[0] [0] ，所以输出的是 0 吗？

并不是，注意看 a[3] [2]大括号内的内容，里面是圆括号而不是大括号，这是**逗号表达式**。

所以，a[0] [0] == 1 



#### Ⅴ

```c
int main(void){
	int a[5][5];
	int(*p)[4];
	p = a;
	printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	
    return 0;
}
```



指针（同类型）相减的意义是**两个指针之间间隔的元素个数**

`&p[4][2]` -> 数组中的第 19 个元素（4 * 4 + 3）

`&a[4][2]` -> 数组中的第 23 个元素  (4 * 5 + 3)



答案：FFFFFFFC,-4



#### Ⅵ

```c
int main(void)
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *ptr1 = (int *)(&aa + 1);
	int *ptr2 = (int *)(*(aa + 1));
	printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));
    
	return 0;
}

```

`&aa` 的类型是 `int(*)[2][5]`，所以 `&aa + 1` 指向的是整个数组后面的内存 。所以 `*(ptr1 - 1)` 的值是 10

`aa`  aa + 1 让 aa 隐式转换为 `int(*)[5]` ,所以 `aa + 1` 指向的是元素 6 所在的地址。所以 `*(ptr2 - 1)` 的值是 5



#### Ⅶ

```c
#include <stdio.h>
int main(void)
{
	char *a[] = {"work","at","alibaba"};
	char**pa = a;
	pa++;
	printf("%s\n", *pa);
	
    return 0;
} 
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200306012601867.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)


#### Ⅷ

```c
int main(void)
{
	char *c[] = {"ENTER","NEW","POINT","FIRST"};
	char** cp[] = {c+3,c+2,c+1,c};
	char***cpp = cp;
	printf("%s\n", **++cpp);// ++cpp 会改变 cpp 的值
	printf("%s\n", *--*++cpp+3);//
	printf("%s\n", *cpp[-2]+3);//-2 并没有改变 cpp
	printf("%s\n", cpp[-1][-1]+1);
	
    return 0;
}
```



![在这里插入图片描述](https://img-blog.csdnimg.cn/20200306012612708.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)



单目运算符从右向左依次运算。

```c
char* p = "ENTER";
printf("%s", p + 3);// 输出 ER，p + 3 增加 3 个字节，因为 p 指向的类型是 char 大小是 1 个字节。
```


