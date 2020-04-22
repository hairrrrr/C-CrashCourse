#define _CRT_SECURE_NO_WARNINGS 1

// 这是 atoi 实现的另一个版本
// 上一个版本其实和库里面的 atoi 实现有的地方不是一致的
// 比如库函数 atoi 处理字符串 "abc123", 返回的结果是 0 ，而上一个我实现的 MyAtoi 会返回 123
//                            "+-123", 返回的结果是 0， 而MyAtoi 会返回 -123
// 其实我觉得我都 atoi 函数更强大哈哈
// 但是我们也应该规范一点，毕竟是库函数

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int MyAtoi_2(const char* str) {
	
	int flg = 1;
	int ret = 0;

	if (str == NULL || str == '\0') {
		return 0;
	}

	// 判断是否为空白字符（空格，换行，制表，翻页 ...）
	while (isspace(*str)) {
		str++;
	}

	// 判断是否为正负号
	// 用库函数 atoi 试一下就知道 "+-123" 这种字符串是无法转成数字的，所以这是一种要处理的情况 
	// 如果符号位的下一个不是数字，则返回 0 
	if (*str == '+' || *str == '-' ) {
		
		if (*(str + 1) == NULL) {
			return 0;
		}

		if (!isdigit(*(str + 1))) {
			return 0;
		}

		if (*str == '-') {
			flg = -1;
		}
		str++;
	}

	// 处理数字字符
	while (*str != '\0') {
		if (isdigit(*str)) {
			
			// 判断一下会不会超过 int 的范围
			if (((unsigned long)ret * 10 + (*str - '0')) > INT_MAX) {
				return INT_MAX;
			}
			ret = ret * 10 + (*str - '0');
			
			// 在 MyAtoi 中，我选择用数组存储每一位，然后从后向前依次乘以每一位的权重
			// 但是这样直接加一个数之前先乘以 10 的做法更为简洁
		}
		else {
			return 0;
		}
		str++;
	}

	return ret * flg;
}

int main(void) {

	char str[100];
	int ret;

	scanf("%s", str);

	ret = MyAtoi_2(str);
	
	printf("%d\n", ret);

	return 0;
}

