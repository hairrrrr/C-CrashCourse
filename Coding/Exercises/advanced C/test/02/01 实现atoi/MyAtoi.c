#define _CRT_SECURE_NO_WARNINGS 1

// atoi 实现
// ElementType atoi( const char *str );
//转译 str 所指的字节字符串中的整数值。

//舍弃任何空白符，直至找到首个非空白符，然后接收尽可能多的字符以组成合法的整数表示，并转换之为整数值。合法的整数值含下列部分：

//(可选) 正或负号
//数位

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef long long ElementType;

ElementType MyAtoi(const char* str);
ElementType StrToNum(int numbers[], int size);

int main(void) {

	char str[MAXSIZE];
	ElementType NumInStr;

	scanf("%s", str);
	
	NumInStr = MyAtoi(str);
	
	printf("%lld\n", NumInStr);// 转换成大的类型需要改变 printf 的转换说明

	return 0;
}

ElementType MyAtoi(const char* str) {

	ElementType ret = 0;
	int isFirstNumber = 1;
	int flg = 1;
	int numbers[MAXSIZE];
	int size = 0;

	while (*str != '\0') {
		
		if (*str >= '0' && *str <= '9') {
			// 判断这个数是否为第一个出现的数字，如果是，我们要判断前一个字符是否是 - 号
			if (isFirstNumber) {
				if (*(str - 1) == '-')
					flg = -1;
				isFirstNumber = 0;
			}
			// 直接将字符转化为数字放入数组内，数组放置的是目标数字的每一位（不带权重）。
			numbers[size++] = *str - '0';// 数字对应的 ACSII 码值减去 ‘0’对应的 ASCII 值就是实际上数组表示的值
		}
		++str;
	}

	ret = StrToNum(numbers, size);

	return (flg * ret);
}

ElementType StrToNum(int numbers[], int size) {

	ElementType ret = 0;
	ElementType weight = 1;
	int i;

	for (i = size - 1; i >= 0; i--) {
		ret += numbers[i] * weight;
		weight *= 10;
	}

	return ret;
}

