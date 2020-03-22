#define _CRT_SECURE_NO_WARNINGS 1

// 字符串的左旋问题包含两点：
// 1. 左旋字符串
// 2. 判断字符串是否是另一个字符串左旋得到的
// 这次我们一起处理这两个问题。

#include<stdio.h>
#include<string.h>

// 让字符串左旋，我们可以先实现一个函数左旋一个字符，然后用另一个函数去调用这个函数，实现旋转多个字符

void LeftRotateOne(char str[], int size) {

	char tmp;
	int i;

	if (str == NULL)
		return;

	if (size == 1)
		return;

	// 先备份字符串第一个元素
	tmp = str[0];
	
	// 将字符串从第二个元素开始依次向前移动一位
	for (i = 1; i < size; i++) {
		str[i - 1] = str[i];
	} 

	str[size - 1] = tmp;

}

// 这样的算法，如果 size 比较大，效率是很低的，因为数组每次移动复杂度都是 O(n)
void LeftRotateN(char str[], int size, int n) {
	
	if (str == NULL)
		return;

	// 求模是因为：比如 “ABCD” 左旋 4 次 等于没左旋
	for (int i = 0; i < n % size; i++) {
		LeftRotateOne(str, size);
	}
}
// 判断 str1 str2 是否互为左旋
int LeftRotateCmp(char str1[], char str2[]) {

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return -1;

	if (len1 != len2)
		return 0;

	// 将 str1 用 for 循环左旋 len1 次，每次左旋后与 str2 比较
	// 其实最多只用循环 len1 - 1 次即可，但是如果 写成 i < len1 - 1
	// 最后依次旋转的结果不会被比较！！而且即使多旋转了一次，相当于判断结束将 str1 归位了，一举两得！
	for (int i = 0; i < len1; i++) {
		if (strcmp(str1, str2) == 0) {
			return 1;
		}
		LeftRotateOne(str1, len1);
	}

	return 0;
}

int main(void) {

	char str[] = "ABCD";
	char str1[] = "DABC";

	//LeftRotateOne(str, strlen(str));
	//LeftRotateN(str, strlen(str), 4);
	int a = LeftRotateCmp(str, str1);

	printf("%d", a);

	return 0;
}

