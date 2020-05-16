#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 数组法（不对称边界）
int* bsearch(int* arr, int n, int key) {
	
	//对于不对称边界来说，mid 的取值为 lo <= mid < hi
	int lo = 0;
	int hi = n;

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] > key)
			hi = mid;
		else if (arr[mid] < key)
			lo = mid + 1;
		else
			return arr + mid;
	}

	return NULL;
}

// 指针法（不对称边界）
int* bsearch(int* arr, int n, int key) {

	int* lo = arr;
	int* hi = arr + n;

	while (lo < hi) {
		int* mid = lo + ((hi - lo)>>2); //指针的加法是没有意义的
		if (*mid > key)
			hi = mid;
		else if (*mid < key)
			lo = mid + 1;
		else
			return mid;
	}

	return NULL;
}

// 数组法（对称边界）
int* bsearch(int* arr, int n, int key) {

	//对于对称边界来说，mid 的取值为 lo <= mid <= hi
	int lo = 0;
	int hi = n - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] > key)
			hi = mid + 1;
		else if (arr[mid] < key)
			lo = mid + 1;
		else
			return arr + mid;
	}

	return NULL;
}
