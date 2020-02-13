#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"Array.h"

//typedef struct _node {
//
//	char name[20];
//	char gender[5];
//	int age;
//	long long ID;
//}node;

int main(void) {

	node* head = NULL;
	int count = 1;
	int Exit = 0;

	do {
		printf("是否继续？输入 0 退出\n");
		scanf("%d", &Exit);

		if (Exit) {
			printf("请输入第 %d 个学生信息\n", count++);
			node* p = (node*)malloc(sizeof(node));
			printf("\t\t姓名: ");
			scanf("%s", p->Name);
			printf("\t\t性别: ");
			scanf("%s", p->Gender);
			printf("\t\t年龄: ");
			scanf("%d", &(p->Age));
			printf("\t\t学号: ");
			scanf("%lld", &(p->ID));

			p->next = NULL;

			node* last = head;//创建新的节点需要寻找最后一个放 NULL 的节点

			//如果表头是空指针
			if (last) {
				//节点 指针域为NULL 找到了
				while (last->next)
					last = last->next;
				last->next = p;
			}
			else
				head = p;
		}
	} while (Exit);


	return 0;
}




