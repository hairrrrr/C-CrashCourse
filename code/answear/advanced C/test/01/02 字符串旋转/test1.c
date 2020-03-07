#include<stdio.h>
#include<string.h>
#include<assert.h>

int strJudge(const char* str1, const char* str2) {

	char* str2_start = (char*)str2;

	//str1 和 str2 不能是空指针
	assert(str1 != NULL && str2 != NULL);

	//如果字符串长度是 1 ，这个判断就没有意义了
	assert(strlen(str1) != 1);
	
	//如果连个字符串长度都不一样，肯定不是
	if (!(strlen(str1) == strlen(str2)))
		return 0;

	//在 str2 中寻找 str1 的第一个元素
	while (*str2) {
		if (*str2 == *str1) {
			++str1;// str1 中的第一个元素已经找到，在下一个循环寻找 str1 中的下一个
			break;
		}

		++str2;
	}
	//没有找到，直接返回 0
	if (*str2 == '\0')
		return 0;

	while (*str1) {
		
		++str2;

		if (*str2 == '\0')
			str2 = str2_start;
		
		if (!(*str2 == *str1))
			return 0;

		++str1;
	
	}

	return 1;
}

int main(void) {

	char str1[100];
	char str2[100];

	printf("Enter two strings: ");
	scanf("%s %s", str1, str2);

	if (strJudge(str1, str2))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
