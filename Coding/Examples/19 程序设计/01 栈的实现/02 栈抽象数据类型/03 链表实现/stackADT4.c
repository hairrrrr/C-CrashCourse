#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"stackADT4.h"

typedef struct node{
	Item data;
	struct node* next;
}node;

typedef struct stack_type {
	node* top;
}stack_type;


static void terminate(char* message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create() {
	Stack s = (Stack)malloc(sizeof(stack_type));
	if (s == NULL) {
		terminate("Error in create: stack could not be created.\n");
		exit(EXIT_FAILURE);
	}
	s->top = NULL;

	return s;
}

void destory(Stack s) {
	
	make_empty(s);
	free(s);
}



void make_empty(Stack s) {
	while (!is_empty(s))
		pop(s);
}

bool is_empty(Stack s) {
	return s->top == NULL;
}

bool is_full(Stack s) {
	return false;
}

void push(Stack s, Item i) {

	node* new_node = (node*)malloc(sizeof(node));
	if (new_node == NULL) {
		terminate("Error in push: stack is full.\n");
		exit(EXIT_FAILURE);
	}

	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

Item pop(Stack s) {

	if (is_empty(s))
		terminate("Error in pop: stack is empty.\n");

	int data = s->top->data;

	node* del = s->top;
	s->top = s->top->next;
	free(del);

	return data;
}
