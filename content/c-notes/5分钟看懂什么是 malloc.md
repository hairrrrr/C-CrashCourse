

# 初识 动态内存分配 
###      动态内存分配的引入
初学数组的时候，有一个问题经常困扰着我，就是：我们可不可以**自己在程序里定义一个数组的大小**而不是在函数开头先声明一个很大的数组，然后仅仅使用它的一小部分？

请看下面的程序：
我们需要一个大小为 N ( N < 1000)的数组,我们通常这么写：
```c
int main(void) {

	int arr[1000] = { 0 };
	int N = 0;
	int i = 0;

	printf("请输入数组的大小\n");
	scanf("%d", &N);

	printf("请输入%d个数\n", N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	return 0;
}
```
每次这么写我都觉得自己在绕远路，为什么就不能直接把输入的变量 N 当作数组的大小直接使用？
比如这样：`arr[N]`，但是很遗憾，每次编译器都把你扼杀在程序编译之前！
![](https://img-blog.csdnimg.cn/20200204000901763.gif)
>C99才可以用变量做数组定义的大小
>并且可以在程序中随时声明变量。（C99前我们需要在函数的最前面的区域对所有变量进行声明）

如果我不想用上面那种笨笨的办法，又没有支持C99的编译器，我该怎么办？

可以这么做：
`int* arr = (int*)malloc(sizeof(int) * N)`

`sizeof(int)` 代表数组中每个元素的类型
`N` 代表数组的元素个数

所以malloc的意义是向 堆区 要了一块`sizeof(int) * N` 这么大的空间

### malloc 与  free ——好哥俩
#### malloc
>**头文件**：`stdlib`
>**原型**：`void* malloc(size_t size)`
>所以需要根据实际你需要的类型对其强制类型转换
>**返回值**：
>成功时，返回指向新分配内存的指针。为避免内存泄漏，必须用 free() 或 realloc() 解分配返回的指针。
>失败时，返回空指针（NULL）
>**参数**：size	-	要分配的字节数
>***
>**定义**
>分配 size 字节的未初始化内存。
>若分配成功，则返回为任何拥有基础对齐的对象类型对齐的指针。
>  ——
>若 size 为零，则 malloc 的行为是实现定义的。例如可返回空指针。亦可返回非空指针；但不应当解引用这种指针，而且应将它传递给 free 以避免内存泄漏。
>[更多关于malloc](https://zh.cppreference.com/w/c/memory/malloc)


#### free
>**头文件**：`stdlib`
>**原型**：`void free( void* ptr );`
>**参数**：指向要解分配的内存的指针
>**返回值**：无
>**此函数接收空指针（并对其不处理）以减少特例的数量。不管分配成功与否，分配函数返回的指针都能传递给 free()**
>——
>这是什么意思？意思就是malloc与free成对出现，不要忘记写free哦。
>***
>定义：
>解分配之前由 malloc() 、 calloc() 、 aligned_alloc (C11 起) 或 realloc() 分配的空间。
>——
>**若 ptr 为空指针，则函数不进行操作**。[^1]
>——
>**若 ptr 的值 不等于之前从 malloc() 、 calloc() 、 realloc() 或 aligned_alloc() (C11 起) 返回的值**[^2]，则行为未定义。
>——
>**若 ptr 所指代的内存区域已经被解分配[^3]**，则行为未定义，即是说已经以ptr 为参数调用 free() 或 realloc() ，而且没有后继的 malloc() 、 calloc() 或 realloc() 调用以 ptr 为结果。
>——
>**若在 free() 返回后通过指针 ptr 访问内存[^4]**，则行为未定义（除非另一个分配函数恰好返回等于 ptr 的值）。
>[更多关于free](https://zh.cppreference.com/w/c/memory/free)


**free()**：将申请来的空间的 **首地址** 还给“系统”，只要申请到了空间就**一定要归还**

毕竟有借有还，再借不难嘛
<br/>
#### 解读 free

注释1：释放空指针有何意义？
>我们在声明一个指针时，一般把它初始化为0，也就是NULL。
>——
>这样做的好处是，如果我们在后面的程序中没有让这个指针指向一块具体的空间，这个指针不会是野指针，方便我们用来判断。比如`if(p != NULL)`
>——
>我们还知道，当malloc失败时返回的是 NULL
>所以我们一开始写上free是好习惯，因为我们不知道我们会不会用到我们声明的指针，也不知道malloc能不能成功
>这时候，free空指针就是有意义的了

 注释2：molloc申请到的指针 与 free要释放的指针保持一致
```c
#include<stdio.h>

int main() {

	int* p;

	p = (int*)malloc(100 * 1024);
	
	p++;	//改变了 p 的首地址;

	free(p);//free 没有得到 malloc时 分配给p的首地址，程序崩溃
	return 0;
}
```

注释3：free释放空间后，被释放的指针成为野指针，不能直接使用它 

```c
#include<stdio.h>

int main() {

	int* p;

	p = (int*)malloc(100 * 1024);
	
	p++;

	free(p);
	p++;//free 释放后 p 成为了野指针，程序崩溃

	return 0;
}
```

注释4：不能多次释放同一次malloc申请的地址

```c
#include<stdio.h>

int main() {

	int* p;

	p = (int*)malloc(100 * 1024);

	p++;

	free(p);
	free(p);

	return 0;
}
```

<br/>

**现在我们就可以改进我们上面的程序啦！**
```c
#include<stdlib.h>

int main(void) {

	int i = 0;
	int N = 0;
	int* arr;

    printf("请输入数组的大小\n");
	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int) * N);

	printf("请输入%d个数\n", N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	free(arr);
	return 0;
}
```
<br/>

什么？不是改进吗？怎么行数反而变多了？
![](https://img-blog.csdnimg.cn/20200204003505997.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70 =300x300)


#### 测测你能给系统分配多大空间？
```c
#include<stdlib.h>

int main(void) {
	
	void* p;
	int i = 0;
     
    //每次申请100M，失败返回空指针0，退出循环
	while ((p = malloc(1024 * 1024 * 100)))
		i++;

	printf("最多分配%d00M内存", i);

	return 0;

}
```
#### 如果忘记了free？
我们一次程序中可以申请的内存是有限的。

如果你只是平时写简单的程序，写完就关闭，退出去了，这时忘记了free的话，不会对任何人造成影响，因为操作系统有清除曾使用的内存的机制

但是如果是一个持续运行的服务器呢？堆区中所有的空间都被你申请了呢？

###### free的常见问题
>- 申请了没有free  ->  长时间运行内存逐渐下降
>- free 后再free
>- 地址变更后，直接去free

***
###### 小测试：
1.对于以下的代码段，正确的说法是：
```c
char *p;
while(1){
     p = malloc(1);
    *p = 0;
}
```
A:最终程序会因为没有空间了而退出
B:最终程序会因为向0地址写入而退出
C:程序会一直运行下去
D:程序不能被编译

2.对于以下代码段：
```c
int a[] = {1, 2, 3, 4, 5};
int *p = a;
int *q = &a[5];
printf("%d",q-p);
```
当 `sizeof(int) = 4`时，以下说法正确的是：
A：因为第三行的错误不能编译
B：因为第三行的的错误运行时崩溃
C：输出5
D：输出20

3.使用malloc就可以做出运行时可以随时改变大小的数组
A：√
B：❌

查看答案可在后台回复：**2020 0204**查看答案哦
***
欢迎各位与我交流讨论！