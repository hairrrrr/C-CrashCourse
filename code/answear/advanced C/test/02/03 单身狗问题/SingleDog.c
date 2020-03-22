#define _CRT_SECURE_NO_WARNINGS 1

// 找单身狗问题：
// 1. 现有一个数组，只有一个元素只出现了一次，其他元素都出现了两次，请找出这个元素。
// 2. 如果数组中有两个元素只出现了一次，其他都出现了两次，请找出这两个元素。

// 这两个问题都应用到了按位异或
// 如果两个相同的数按位异或结果为零
// 我们在前面的 两数平均值求法 中用异或来求出两数 二进制位 中 不同的位 表示的数的 和


#include<stdio.h>

int FindOneSingleDog(int arr[], int size) {

	int Dog = arr[0];

	for (int i = 1; i < size; i++) {
		Dog = Dog ^ arr[i];
	}

	return Dog;
}

void FindTwoSingleDog(int arr[], int size, int* Dog1, int* Dog2) {
	
	int rst = arr[0];
	int leftPos = 0;

	for (int i = 1; i < size; i++) {
		rst = rst ^ arr[i];
	}
	//此时 rst 等价于 Dog1 ^ Dog2, 这个结果的比特位一定有一个是 1
	
	// 找到第一个是 1 的比特位
	for (leftPos = 0; leftPos < 32; leftPos++) {
		if ((rst & (1 << leftPos)) == 1) {
			break;
		}
	}

	// 将数组元素分成两部分，一部分 leftPos 位为 1，另一部分不为 1
	// 那么 Dog1 和 Dog2 就在不同的组内了。再次按位异或，结果就是 Dog1 和 Dog2 的值
	
	*Dog1 = 0;
	*Dog2 = 0;

	for (int i = 0; i < size; i++) {
		// leftPos 为 1 的组
		if ((arr[i] & (1 << leftPos)) == 1) {
			*Dog1 = *Dog1 ^ arr[i];
		}
		else {
			*Dog2 = *Dog2 ^ arr[i];
		}
	}


}

int main(void) {

	int arr1[] = { 1, 2, 3, 4, 1, 2, 3 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int Dog;
	
	int arr2[] = { 1, 1, 2, 2, 3, 4 };
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int Dog1, Dog2;

	Dog = FindOneSingleDog(arr1, size1);

	FindTwoSingleDog(arr2, size2, &Dog1, &Dog2);

	return 0;
}

