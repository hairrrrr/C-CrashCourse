//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include"stackADT3.h"
//
//
//typedef struct stack_type {
//	int top;
//	int size;
//	Item contents[]; // 柔性数组
//}stack_type;
//
//
//
//static void terminate(char* message) {
//	printf("%s\n", message);
//	exit(EXIT_FAILURE);
//}
//
//Stack create(int size) {
//	
//	// sizeof(stack_type) 的大小不含有柔性数组
//	Stack s = (Stack)malloc(sizeof(stack_type) + sizeof(Item) * size);
//	if (s == NULL) {
//		terminate("Error in create: stack could not be created.\n");
//		exit(EXIT_FAILURE);
//	}
//	s->top = 0;
//	s->size = size;
//
//	return s;
//}
//
//
//void destory(Stack s) {
//
//	free(s); // 柔性数组只需要释放一次
//}
//
//
//void make_empty(Stack s) {
//
//	s->top = 0;
//}
//
//bool is_empty(Stack s) {
//	return s->top == 0;
//}
//
//bool is_full(Stack s) {
//	return s->top == s->size;
//}
//
//void push(Stack s, Item i) {
//
//	if (is_full(s)) {
//		terminate("Error in push: stack is full.\n");
//		exit(EXIT_FAILURE);
//	}
//
//	s->contents[s->top++] = i;
//}
//
//Item pop(Stack s) {
//
//	if (is_empty(s)) {
//		terminate("Error in pop: stack is empty.\n");
//		exit(EXIT_FAILURE);
//	}
//
//	return s->contents[--s->top];
//}