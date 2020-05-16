#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

char* MyStrncpy(char* dest, char* src, int count);

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

		MyStrncpy(dest, src, count);

		printf("%s\n", dest);

	return 0;
}

// 这个函数同样是考虑不周全的：
// 1. count 如果大于 字符数组dest 怎么办？
// 2. count 大于 src 而 src 没有空字符怎么办？

char* MyStrncpy(char* dest,const char* src, int count) {

	assert(dest && src);
	char* begin = dest;
	
	while (count-- && (*begin++ = *src++));
	
	// count 如果小于 src 的长度，那么得到的字符串是不含空字符的。
	// 加上 \0 是保险的。
	if (count + 1 == 0) {
		*begin = '\0';
	}
	else {
		while (count--) {
			*begin++ = *src++;
		}
	}
	
	return dest;
}

