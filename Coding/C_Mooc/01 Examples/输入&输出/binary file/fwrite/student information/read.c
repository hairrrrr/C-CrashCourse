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