#define _CRT_SECURE_NO_WARNINGS 1

// strncat 实现

#include<stdio.h>
#include<assert.h>

char* MyStrncat(char* dest, const char* src, int count);

int main(void) {

	char dest[100];
	char src[50];
	int count = 0;

	printf("Enter string dest: ");
	scanf("%s", dest);
	printf("Enter string src: ");
	scanf("%s", src);
	printf("Enter number of character(s) copy  from src to dest: ");
	scanf("%d", &count);

	MyStrncat(dest, src, count);
	
	printf("%s\n", dest);

	return 0;
}

// 其实我觉得这取实现程序不如不写。这种写法你上网一查都是一大片一大片的，
// 乍一看感觉是对的，但是自己想一想，这是很危险的写法。当让你也可以归结于
// C语言本身的语法不好，但是其实是我们的水品还没到罢了，我们想不到更好的写法，
// 我们根本没学精 C！但是这糟糕的函数是 C 的创始人写出来的啊！似乎可以为我们找一些接口。

// 现在我们来说一下这样的写法有什么漏洞，首先，我们看一看 cppreference 上给的定义：

//后附来自 src 所指向的字符数组的至多 count 个字符，到 dest 所指向的空终止字节字符串的末尾，
//若找到空字符则停止。字符 src[0] 替换位于 dest 末尾的空终止符。
//始终后附终止空字符到末尾（故函数可写入的最大字节数是 count + 1 ）。

//若目标数组没有对于 dest 和 src 的首 count 个字符加上终止空字符的足够空间，
//则行为未定义。若源与目标对象重叠，则行为未定义。若 dest 不是指向空终止字节字符串的指针，
//或 src 不是指向字符数组的指针，则行为未定义。

// 现在我来说一下我认为这个程序可能存在的问题:
// 1.dest 函数本身加上 count 个字符是否会造成数组越界？
// 2.dest 函数有没有 '\0' 我没有检测。如果没有，则很有可能造成越界，并且将造成非法内存访问和改写。
// 3.如果 src 没有 '\0' 而 count 又大于 src字符数组有意义内容的大小，或者 src字符数组本身的大小，
//   这时也会造成非法内存访问。
// 4.src 是不是指向字符数组的指针？

// 如果还有问题欢迎补充，如果你有更好的解法（C语言）欢迎告诉我，我会加上你的真知灼见！（私信我即可） 

char* MyStrncat(char* dest, const char* src, int count) {

	assert(dest && src);
	
	char* NewStr = dest;

	// 循环结束 NewStr 指向 dest 字符串 '\0' 所在位置 
	while (*NewStr != '\0') {
		++NewStr;
	}
	while (count-- && (*NewStr++ = *src++));

	*NewStr = '\0';

	return dest;
}

