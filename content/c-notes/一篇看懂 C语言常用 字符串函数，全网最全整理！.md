字符串函数 指的是头文件 ` stdio.h ` 中的输入输出函数 和 头文件`string.h`里定义的我们平时直接使用的函数。
一下是本节重点讲解的 10 个函数。对于生僻点的字符串函数我们以后再讲。

- putchar & getchar
- strlen & strnlen_s
- strcmp & strncmp
- strcpy & strncpy
- strcat & strncat

这些函数我们到处在用，可你有没有想过，究竟这些函数是怎么声明和定义的？他们远没有你想的那么简单。

**以下被划掉的部分如果你理解，那是最好。不理解不可以不用纠结，~~慢慢来~~**
![](https://img-blog.csdnimg.cn/20200206205235611.jpg)
### （一）putchar & getchar
#### putchar
>`int putchar( int ch )`
>**头文件**：stdio.h
>**定义**：写字符 ch 到 stdout 。在内部，字符于写入前被转换到 unsigned char 。
>*stdout：标准输出 我们后面会单独讲*
>意思就是：向标准输出写入一个字符
>~~等价于 putc(ch, stdout) 。~~
>**参数**： `ch` 要被写入的字符串
>**返回值**：
>成功时返回写入的字符。
>失败时返回 EOF ~~并设置 stdout 上的错误指示器~~
>*EOF（end of file）是一个宏，值为 -1*

第一次看到这个函数的 返回类型 和 参数类型 我其实很懵：
嗯？
我输入的不是 char 类型的吗？ 怎么参数类型是 int ?
我看到的不是 char 类型的 `A` 吗？怎么返回类型是 int？

![](https://img-blog.csdnimg.cn/20200206220023221.jpg)
其实，输出是什么不代表返回就是什么。scanf还返回整数呢，照样可以输出汉字。

下面的程序帮助大家理解：
```c
int main(void) {

	char ch = 'A';

	int a = 0;

	a = putchar(ch);

	printf("\n%d", a);

	return 0;

}
```
输出：
```c
A
65
```

上面我说慢慢来的时候也许有同学不屑：“这还用慢慢来？早会了！”
那好吧，`putchar` 的上面的定义中说它等价于 `putc` 
要不我们再来看看 putc 是怎么定义的？与 putc 类似的还有个 `fputc`
要想真正理解它们还得看看 `ferror`，一个个来呗？
![](https://img-blog.csdnimg.cn/202002062210064.jpg)
A watched pot never boils —— 心急吃不了热豆腐
#### getchar
>`int getchar(void)`
>**头文件**：stdio.h
>**定义**：
>从 stdin 读取下一个字符。
>~~等价于 getc(stdin) 。~~
>也就是 从标准输入读入一个字符
>**参数**：无
>**返回值**：
>成功时为获得的字符
>失败时为 EOF 。

#### getchar的返回值有什么用？
如何退出下面程序中的 while循环？
可以自己打出来先测试一下。
```c
int main(void) {

	int ch;
	
	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}

	printf("EOF\n");
	//退出循环的方式可能有两种：
	//1.程序被关闭。EOF不会输出
	//2.退出了循环，程序继续向下运行。EOF会被输出

	return 0;
}
```
后面还会继续详细讲解 这部分知识。可以自行思考一下，也可以查阅资料看看。
我做了一个便于理解的图示，如果现在就想看，在公众号回复[0206]查看。

*为了减少冗余，下面的程序我只写 main 函数部分，
但是在你写程序到时候你要记得引用头文件 string.h*

### （二）strlen & strnlen_s
帮你理解：
strlen： string lenth 
####  strlen 
>`size_t strlen( const char *str )`
>**头文件**：`string.h`
>**参数**：str	-	指向要检测的空终止字符串的指针
>**返回值**： 空终止字节字符串 str 的长度。
>***
>**定义**：返回给定空终止字符串的长度，即首元素为 str 所指，且不包含首个空字符的字符数组中的字符数。
> 若 str 不是指向空终止字节字符串的指针则行为未定义。

*什么是 空终止字节字符串？
空终止字节字符串（ NTBS ）是尾随零值字节（空终止字符）的非零字节序列。字节字符串中的每个字节都是一些字符集的编码。例如，字符数组 {'\x63','\x61','\x74','\0'} 是一个以 ASCII 编码表示字符串 "cat" 的 NTBS 。*

#### strnlen_s
>`size_t strnlen_s( const char *str, size_t strsz )`
>**头文件**：`string.h`
>**参数**：
>str	-	指向要检测的空终止字符串的指针
>strsz	-	要检测的最大字符数量
>**返回值**：
>成功时为空终止字节字符串 str 的长度，若 str 是空指针则为零，若找不到空字符则为 strsz 。
>***
>**定义**：
>除了若 str 为空指针则返回零，而若在 str 的首 strsz 个字节找不到空字符则返回 strsz 。
>若 str 指向缺少空字符的字符数组且该字符数组的大小 < strsz 则行为未定义；~~换言之， strsz 的错误值不会暴露行将来临的缓冲区溢出。~~

#### strlen 与 strnlen_s 的区别与用法
**1.空指针**
```c
int main() {

	char* str = NULL;
	
	//str为空指针，行为未定义。程序会崩溃
	printf("%d\n", strlen(str));
	
	//str为空指针，返回 0
	printf("%d\n", strnlen_s(str, 1));

	return 0;
}
```
**2.没有终止符的字符串数组当作函数参数**
```c
int main() {

	char str[] = { 'H', 'E', 'L', 'L', 'O', };
	
	printf("%d\n", strlen(str));

	printf("%d\n", strnlen_s(str, (size_t)sizeof(str)));

	return 0;
}
```
猜一猜会输出什么？
```c
19
5
```
**当我们不清楚字符串中有没有 '\0' 时，我们要小心使用 strlen**
strlen 只有遇到 '\0' 才会停止，这造成的潜在的数组越界风险。

**3. 当 strsz > str的大小 时**
1）若 str 有终止符
```c
int main() {

	char str[] = { 'H', 'I', '!', 0 };

	printf("%d\n", strnlen_s(str, 5));

	return 0;
}
```
```c
3
```
2) 若 str 无终止符， 行为未定义
```c
int main() {

	char str[] = { 'H', 'I', '!'};

	printf("%d\n", strnlen_s(str, 5));

	return 0;
}
```
```c
5
```
最后，对于 `strnlen_s `来说**如果 strsz < str数组大小**，直接返回 strsz

#### strlen 详解
###### const的作用
`size_t strlen( const char *str )`

const 的作用是什么？
简单来说，如果你不希望这个函数改变你传入的数组，const 具有保护作用，使得 strlen 函数内部无法改变 str 数组每个元素的值。

const详解可以参考这篇文章：
[点击查看](https://mp.weixin.qq.com/s/Fc-sAgpXmJ1eVKufZCvN8A)

#### mystrlen
mystrlen 的写法有很多，如果你的编译器是 VS，你甚至可以直接看编译器是如何去写的。
一下提供一种比较简洁的写法供大家参考：

不难（你细品

```c
int mystrlen(const char* str) {
	
	char* end = str;
	
	while ( *end++ );

	//退出while循环时，多加了一次 1
	return (end - start - 1);

}

int main() {

	char* str = "Hello World!";

	printf("%d\n", mystrlen(str));

	return 0;
}
```
![](https://img-blog.csdnimg.cn/2020020814321837.jpg)
###  (三) strcmp & strncmp
如何记忆？
strcmp:string compare
lhs:left-hand side
rhs:right-hand side
#### strcmp
>`int strcmp( const char *lhs, const char *rhs )`
>**头文件**：`string.h`
>**参数**：
>lhs, rhs	-	指向要比较的空终止字节字符串的指针
>**返回值**：
>若字典序中 lhs 先出现于 rhs 则为负值。
>若 lhs 与 rhs 比较相等则为零。
>若字典序中 lhs 后出现于 rhs 则为正值。
>***
>*什么是字典序？*
>*简单理解就是在字母表中出现的顺序。*
>*记法小窍门：*
>*lhs ASCII码值大 就为正 否则为负*
>*解释：ASCII值大在字典序中肯定靠后，是后出现的*
>***
>**定义**：
>以字典序比较二个空终止字节字符串。
>结果的符号是被比较的字符串中首对不同字符（都转译成 unsigned char ）的值间的差的符号。
>若 lhs 或 rhs 不是指向空终止字节字符串的指针，则行为未定义。

### strncmp
>`int strncmp( const char *lhs, const char *rhs, size_t count )`
>**头文件**：`string.h`
>**参数**：
>lhs, rhs	-	指向要比较的可能空终止的数组的指针
>count	-	要比较的最大字符数
>**返回值**：
>若字典序中 lhs 先出现于 rhs 则为负值。
>若 lhs 与 rhs 比较相等，或若 count 为零，则为零。
>若字典序中 lhs 后出现于 rhs 则为正值。
>***
>**定义**：
>比较二个可能空终止的数组的至多 count 个字符。按字典序进行比较。不比较后随空字符的字符。
>结果的符号是被比较的数组中首对字符（都转译成 unsigned char ）的值间的差的符号。
>若出现越过 lhs 或 rhs 结尾的访问，则行为未定义。若 lhs 或 rhs 为空指针，则行为未定义。
#### strcmp 与 strncmp 比较
**1. lhs 或 rhs 为非空终止字符字符串**
```c
int main() {

	char str2[3] = { 'J', 'I', 'M' };
	//'M' 后的字符是不可预测的。但是肯定都比0大，所以输出 0 或 1
	//你可以试试将 str1 也改为 str2 的数组形式， 试试结果会不会为 -1
	char str1[3] = "JIM";
	
	printf("%d\n", strcmp(str1, str2));
	

	return 0;
}
```
**2. count 的作用**
```c
int main() {

	char* str1 = "Helloa";
	char* str2 = "HelloA";

	printf("%d\n", strcmp(str1, str2));
	//输出 1, str1 > str2
	
	printf("%d\n", strncmp(str1, str2, 5));
	//输出 0， str1 = str2
	return 0;
}
```
**3. "Hello" 与 "Hello " 的区别？**
字符串 "Hello" 是小于字符串 "Hello " 的。（用strcmp函数检测）
因为最后一次字符比较是 '\0' 与 ' '比较，
'\0'  ASCII码值为 0， ' ' ASCII码值为 32
如图：
![](https://img-blog.csdnimg.cn/20200208155506396.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)
```c
int main() {

	char* str1 = "Hello";
	char* str2 = "Hello ";

	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strncmp(str1, str2, 10));

	return 0;
}
```
输出：
```c
-1
-1
```

#### mystrcmp
先想后做，事半功倍：
1. 按字符比较，都相等返回0；
    出现不相等，返回 *lhs - *rhs 的差值
2. *lhs 或 *rhs 遇到 '\0' 退出循环返回 差值

```c
int mystrcmp(char* str1, char* str2) {
	
	while (1) {
		if (*str1 != *str2)
			break;
		else if (*str1 == 0)
			break;
		else
			++str1, ++str2;
	}

	return (*str1 - *str2);
}

int main() {

	char* str1 = "Hello";
	char* str2 = "Hello";

	printf("%d\n", mystrcmp(str1, str2));

	return 0;
}
```
上面的 mystrcmp  看着很笨，当然是可以改进的。
自己思考一下。
答案放在了我的GitHub上。[点击查看](https://github.com/hairrrrr/C-CrashCourse/tree/master/C%20Crash%20Course/13%20String/Prelesson/code/mystrcmp)
对你有帮助，麻烦给我点个小星星哦，方便下次查看。
如果你有更好的解法，欢迎 pull request ！

![胜利在望！](https://img-blog.csdnimg.cn/20200208174239803.jpg)
### (四) strcpy & strncpy
帮助理解：
strcpy:string copy
dest:destination
src:source
#### strcpy
>`char *strcpy( char *dest, const char *src )`
>**头文件**：`string.h`
>**参数**：
>dest	-	指向要写入的字符数组的指针
>src	-	指向要复制的空终止字节字符串的指针
>**返回值**：
>返回 dest 的副本
>***
>**定义**：
>复制 src 所指向的空终止字节字符串，包含空终止符，到首元素为 dest 所指的字符数组。
> 若 dest 数组长度不足则行为未定义。
> 若字符串覆盖则行为未定义。
> 若 dest 不是指向字符数组的指针或 src 不是指向空终止字节字符串的指针则行为未定义。

#### strncpy
>`char *strncpy( char *dest, const char *src, size_t count )`
>**头文件**：`string.h`
>**参数**：
>dest	-	指向要复制到的字符数组的指针
>src	-	指向复制来源的字符数组的指针
>count	-	要复制的最大字符数
>**返回值**：
>返回 dest 的副本
>
>***
>**定义**：
>复制 src 所指向的字符数组的至多 count 个字符（包含空终止字符，但不包含后随空字符的任何字符）到 dest 所指向的字符数组。
>**若在完全复制整个 src 数组前抵达 count ，则结果的字符数组不是空终止的。**
> 若在复制来自 src 的空终止字符后未抵达 count ，则写入额外的空字符到 dest ，直至写入总共 count 个字符。
> 若字符数组重叠，
> 若 dest 或 src 不是指向字符数组的指针（包含若 dest 或 src 为空指针），
> 若 dest 所指向的数组大小小于 count ，
> 或若 src 所指向的数组大小小于 count 且它不含空字符，
> 则行为未定义。

#### strcpy 与 strncpy 的未定义行为
**1. dest 和 src 一定不能是空终止字节字符串， 且要指向字符串**
**2.  dest 与 src 覆盖**
从 C99起 strcpy函数原型变成了这样：
`char *strcpy( char *restrict dest, const char *restrict src )`
`restrict` 表示两个字符串是不重叠的
重叠并不是重复一样的意思。这一点我们目前不去深入。

**3. dest 长度小于 src**
```c
int main() {

	char* str1 = "Hello";
	char* str2 = "Hello World";

	strcpy(str1, str2);
	strncpy(str1, str2, 12);

	puts(str1);

	return 0;
}
```
这样写是可以通过编译的，但是你要知道这样做实际上已经越界了。

如果用数组的形式定义字符串，编译器才会报错。
可以看出，在这种情况下。编译器对数组更为敏感，数组的写法也更加安全。
```c
int main() {

	char str1[] = "hello";
	char str2[] = "hello world";
	
	//两个函数都会报错
	strcpy(str1, str2);
	//strncpy(str1, str2, 12);

	puts(str1);

	return 0;
}
```
**4. strncpy：dest 大小小于 count**
这点其实 3 也说明了。
对于 strcpy 来说， dest 的大小不能小于 src
而 strncpy 只需要 dest 的大小不小于 count 即可

**5. src 大小小于 count 且 src 不含空字符**
```c
int main() {

	char str1[] = "Hello World";
	char str2[] = { 'H', 'e', 'l','l', 'o' };

	strncpy(str1, str2, 10);

	puts(str1);

	return 0;
}
```
输出：
```c
Hello烫烫蘢
```
其实这也不难理解，strncpy 需要 '\0' 来判断 src 是否写完。
如果有 src 结尾有'\0' ，这时如果 count 还没有写满
函数会向 dest 中写入 '\0' 直到写满 count
但是如果 src 没有 '\0' 那么函数不知道 src 已经结束，而继续写入后面的内容，结果可想而知，是不可预测的。

#### mystrcpy
```c
#include<assert.h>

char* mystrcpy(char* str1, char* str2) {
	
	assert(str1 != NULL && str2 != NULL);
	assert(strlen(str1) >= strlen(str2));

	//核心代码从这里开始， 上面的不懂可以加QQ群问我（群在我公众号关注回复的消息里）
	char* after = str1;

	while (*str1++ = *str2++);

	return after;
}

int main() {

	char* str1 = "HI!!!";
	char* str2 = "Hello";

	mystrcpy(str1, str2);
	puts(str1);

	return 0;
}
```
### （五）strcat & strncat
帮你理解：
strcat：string catenate 字符串连接

#### strcat
>`char *strcat( char *dest, const char *src )`
>**头文件**：`string.h`
>**参数**：
>dest	-	指向要后附到的空终止字节字符串的指针
>src	-	指向作为复制来源的空终止字节字符串的指针
>**返回值**：
>返回 dest 的副本
>***
>**定义**：
>后附 src 所指向的空终止字节字符串的副本到 dest 所指向的空终止字节字符串的结尾。字符 src[0] 替换 dest 末尾的空终止符。产生的字节字符串是空终止的。
> 若目标数组对于 src 和 dest 的内容以及空终止符不够大，则行为未定义。
> 若字符串重叠，则行为未定义。
> 若 dest 或 src 不是指向空终止字节字符串的指针，则行为未定义。

#### strncat
>`char *strncat( char *dest, const char *src, size_t count )`
>**头文件**：`string.h`
>**参数**：
>dest	-	指向要后附到的空终止字节字符串的指针
>src	-	指向作为复制来源的字符数组的指针
>count	-	要复制的最大字符数
>**反回值**：
>返回 dest 的副本
>***
>**定义**：
>后附来自 src 所指向的字符数组的至多 count 个字符，到 dest 所指向的空终止字节字符串的末尾，若找到空字符则停止。字符 src[0] 替换位于 dest 末尾的空终止符。始终后附终止空字符到末尾（故函数可写入的最大字节数是 count+1 ）。
> 若目标数组没有对于 dest 和 src 的首 count 个字符加上终止空字符的足够空间，则行为未定义。
> 若源与目标对象重叠，则行为未定义。
> 若 dest 不是指向空终止字节字符串的指针，或 src 不是指向字符数组的指针，则行为未定义。
>

#### strcat 与 strncat 用法解读
**1. strcat：dest >= dest + src + '\0'**
```c
int main() {

	char str1[11] = "Hello";
	char* str2 = " World";
	
	//11刚好可以放下"Hello World"，但是因为没有'\0' 的位置，程序崩溃。
	strcat(str1, str2);
	puts(str1);

	return 0;
}
```
**2. strcpy：dest 或 src 不是 空终止字节字符串**
```c
int main() {

	char str1[11] = "Hello";
	char str2[3] = {'J', 'I', 'M'};//程序崩溃
	
	strcat(str1, str2);
	puts(str1);

	return 0;
}
```
**3. strncpy：dest 不是空终止字节字符串？**
```c
int main() {

	char str1[11] = {'H', 'I'};
	char str2[3] = { 'J', 'I', 'M' };

	strncat(str1, str2, 3);
	puts(str1);

	return 0;
}
```
正确地输出了：
```c
HIJIM
```
可以看出 strncpy 具有某种优化，即使 dest 没有空字符，它也能正确找到正确的后缀位置
即使 src 没有空字符，也可以在新的 dest 后加上空字符


#### mystrcat
```c
char* mystrcat(char* str1, char* str2) {
	//这一步请细品
	while (str1[strlen(str1)] = *str2++);

	return str1;
}

int main() {

	char str1[8] = "Hi";
	char str2[4] = "YOU";

	mystrcat(str1, str2);
	puts(str1);

	return 0;
}
```

***

### 写在后面
![](https://img-blog.csdnimg.cn/20200208222045318.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)
说了半天，其实就是想带大家过一遍我们常用的字符串函数。
里面肯定有你忽略的知识点，希望大家**一定不要放过一些细节**，**一定要多想**，**一定要多写代码**。
重要的事说三遍。
再有就是，不要嫌麻烦。
毕竟你看完可能只要 10 分钟，我写要写好几个小时。

其实这也只是入门的基础概念，真的要学会还是要拿来用。
具体使用有机会再总结吧。

***
**更多精彩内容：**

[指针入门](https://mp.weixin.qq.com/s/0DD10hQQ4411ycbKSpghTw)
[你不知道的素数判断方法](https://mp.weixin.qq.com/s/T-ovU-PIunKFrgH1ZVLOLw)





参考资料：cppreference.com