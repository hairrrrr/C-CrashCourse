#include<stdio.h>

//定义一个 Cmp 类型的函数指针，函数指针返回值是 int,参数是(int, int)
typedef int(*Cmp)(int, int);

void bubbleSort(int arr[], int size, Cmp cmp);
int Asc(int x, int y);
int Desc(int x, int y);

int main(void) {

	int arr[] = { 9, 5, 2, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	bubbleSort(arr, size, Desc);

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void bubbleSort(int arr[], int size, Cmp cmp) {
	
	int i, j;
	int tmp;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			//根据 cmp 函数的规则，如果返回 1，进行 if 语句中的位置互换
			if (cmp(arr[j], arr[j + 1]) == 1) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
				
		}
	}

}
//升序
int Asc(int x, int y) {
	//如果第一个参数比第二个参数大返回 1
	return (x > y ? 1 : 0);
}

//降序
int Desc(int x, int y) {
	return (x < y ? 1 : 0);
}
