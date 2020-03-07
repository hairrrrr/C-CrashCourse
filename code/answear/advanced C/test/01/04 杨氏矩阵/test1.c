//#### 4. 杨氏矩阵
//
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//
//
//
//要求：时间复杂度小于O(N);
//
//*可以先不去管复杂度问题，这里给出一种方便理解的算法。[参考文章](https://blog.csdn.net/sgbfblog/article/details/7745450?depth_1-utm_source=distribute.pc_relevant_right.none-task&utm_source=distribute.pc_relevant_right.none-task)*


#include<stdio.h>
#include<assert.h>

#define ROW 3
#define COL 3

void printArr(int arr[ROW][COL]);
int searchYangMatri(int arr[ROW][COL], int row, int col, int target, int position[2]);

int main(void) {

	int target;
	int position[2] = {-1, -1};//目标数在矩阵中的位置

	//注意：杨氏矩阵并不是有序数列
	int arr[ROW][COL] = {
		{1, 3, 5},
		{2, 4, 6},
		{7, 8, 9},
	};

	printArr(arr);

	printf("Enter a target: ");
	scanf("%d", &target);

	if (searchYangMatrix(arr, ROW, COL, target, position))
		printf("%d is found!The position in the matrix is as follow:(%d, %d)\n", target, position[0], position[1]);
	else
		printf("Not Found!\n");


	return 0;
}

void printArr(int arr[ROW][COL]) {

	int i, j;

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++)
			printf("%d	", arr[i][j]);
		printf("\n");
	}

}

int searchYangMatrix(int arr[ROW][COL], int row, int col, int target, int position[2]) {

	assert(arr != NULL);

	//从矩阵的右上角开始搜寻
	int i = 0;
	int j = col - 1;

	while (i < ROW && j >= 0) {

		//如果目标数比右上角的数大，则去掉这一行（因为右上角的数是这一行中最大的）
		if (target > arr[i][j])
			i++;
		//如果目标数比右上角的小，则去掉这一列（因为右上角的数是这一列中最小的）
		else if (target < arr[i][j])
			j--;
		else {
			position[0] = j;//如果将数组右下角的元素放在二位坐标系的原点上， x 和数组的 列是对应的：x = col（元素所在位置的 col）
			position[1] = row - 1 - i;// y 与 数组行的关系是 y = ROW - 1 - row（元素所在位置的 row）
			return 1;
		}

	}

	return 0;
	
}
