#include<stdio.h>
#include<stdlib.h>
#include "student.h"

void getList(Student* Stu, int num);
int save(Student* Stu, int num);

int main(void) {

	int num = 0;

	printf("请输入学生数量：\n");
	scanf("%d", &num);
	Student* Stu = (Student*)malloc(sizeof(Student) * num);

	getList(Stu, num);

	if (save(Stu, num)) {
		printf("保存成功\n");
	}
	else
		printf("保存失败\n");

	return 0;
}

void getList(Student* Stu, int num) {

	char format[STR_LEN];
	sprintf(format, "%%%ds", STR_LEN - 1);
	//向 format 中写入 %19s
	//%%%ds 前两个%的意义是写入% 
	//%d 输出后面的参数，即：19 
	//最终写入的就是 %19s

	int i = 0;

	for (i = 0; i < num; i++) {

		printf("第 %d 个学生 \n", i + 1);
		printf("\t姓名：");
		scanf(format, Stu[i].name);
		printf("\t性别（0-男 1-女 2-其他）:");
		scanf("%d", &Stu[i].gender);
		printf("\t年龄:");
		scanf("%d", &Stu[i].age);
		//记得用scanf时，何时用 & 
	}

}

int save(Student* Stu, int num) {

	int ret = -1;
	FILE* fp = fopen("student.data", "wx");//如果要向student.data反复写入数据，将 wx 改为 x
	if (fp) {
		ret = fwrite(Stu, sizeof(Student), num, fp);
		//记录 fwrite 的返回值：写入文件的学生个数
		fclose(fp);
	}
	else
		printf("文件打开失败！");

	return (ret == num);
	//如果写入的个数不等于总人数，返回0
}