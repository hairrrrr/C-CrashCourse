#include<stdio.h>

#define HEIGHT 10 //假设杨辉三角的高度是10

int main(void) {

	int YHtrangle[HEIGHT][HEIGHT] = { 0 };
	int i, j;

	//计算杨辉三角
	for (i = 0; i < HEIGHT; i++) {

		YHtrangle[i][0] = 1;//每行第一个元素为 1
		YHtrangle[i][i] = 1;//每行最后一个元素为 1
		//需要计算的是从第三行开始，i == 2
		for (j = 1; j < i; j++)
			YHtrangle[i][j] = YHtrangle[i - 1][j - 1] + YHtrangle[i - 1][j];// 比如第三行的 2 是 第二行 1 + 1的和，这是杨辉三角的规律
	}

	//输出杨辉三角
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j <= i; j++) {
			printf("%d	", YHtrangle[i][j]);
		}
		printf("\n");
	}

	return 0;
}