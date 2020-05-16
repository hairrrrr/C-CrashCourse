#include<stdio.h>

int main(void) {

	printf("%+09d\n", 123);
	printf("%-+09d\n", -123);
	return 0;
}

int main(void) {

	printf("%+09.2f\n", 12.3);
	printf("%-8.3f\n", -12.3);
	return 0;
}

int main(void) {

	int len = 5;
	int dec = 2;
	printf("%*.*f\n",5, 2, 12.3);
	printf("%*.*f\n",len, dec, 12.3);
	return 0;
}

int main(void) {

	printf("%hhd\n", (char)12345);//当作 1 个字节输出
	printf("%hd\n", 12345);//当作 short 输出
	return 0;
}

int main() {

	int num;
	printf("%d%n\n", 123, &num);
	printf("%d\n", num);

	return 0;
}

int main() {

	int num;
	scanf("%*d %d", &num);
	printf("%d\n", num);

	return 0;
}

int main(void) {
	
	float x;
	scanf("%g", &x);
	printf("%F", x);
	
	return 0;
}

int main(void) {

	int num = 0;
	int return_scanf = 0;
	int return_printf = 0;

	return_scanf = scanf("%d", &num);
	return_printf = printf("%d\n", num);

	printf("%d:%d\n", return_scanf, return_printf);
	return 0;
}


FILE* fp = fopen("file", "r");

if (fp) {
	fscanf(fp, ...);
	fclose(fp);
}
else {
	...
}

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
	FILE* fp = fopen("student.data", "w");
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

#include<stdio.h>
#include"student.h"

void read(FILE* fp, int index);

int main(void) {

	FILE* fp = fopen("student.data", "r");
	if (fp) {
		fseek(fp, 0L, SEEK_END);//将文件读/写开始的位置定到结尾
		long size = ftell(fp);//获得从文件开始到文件结尾的字节数
		int index = 0;
		int number = size / sizeof(Student);
		printf("有 %d 个学生数据，你要看第几个\n", number);
		scanf("%d", &index);
		read(fp, index - 1);
	}
	else
		printf("文件打开失败！\n");
}

void read(FILE* fp, int index) {

	fseek(fp, index * sizeof(Student), SEEK_SET);
	
	Student stu;

	if (fread(&stu, sizeof(Student), 1, fp) == 1) {
		printf("第 %d 个学生：\n", index + 1);
		printf("\t姓名：%s\n", stu.name);
		printf("\t性别：");
		switch (stu.gender) {
		case 0:
			printf("男\n");
			break;
		case 1:
			printf("女\n");
			break;
		default:
			printf("其他\n");
			break;
		}
		printf("\t年龄：%d\n", stu.age);
	}
}