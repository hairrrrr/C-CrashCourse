#include<stdio.h>

#define HEIGHT 10 //如果要修改杨辉三角的高度修改这个参数即可

#define ARRLEN HEIGHT + 1 

void printYH(int arr[][ARRLEN]) {

	int row, col;

	//这个程序比较方便惯性思维理解，数组的首行首列不用（下标从 1 开始）
	for (row = 1; row <= HEIGHT; row++) {

		for (col = 1; col <= row; col++) {

			if (col == 1 || col == row)
				arr[row][col] = 1;
			else
				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];

			//直接输出计算结果不需要再用另一个循环输出
			printf("%d	", arr[row][col]);
		}

		printf("\n");
	}
	//当然这个程序也有缺点，如果你在程序中使用这个数组，你需要时刻记得下标为 0 是不存任何有意义的数据的
}

int main(void) {

	int YHtrangle[ARRLEN][ARRLEN] = { 0 };

	printYH(YHtrangle);

	return 0;
}