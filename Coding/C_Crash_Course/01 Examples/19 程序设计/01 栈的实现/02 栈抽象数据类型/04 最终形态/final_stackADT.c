#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"final_stackADT.h"

#define PUBLIC
#define PRIVATE static

typedef struct node{
	Item data;
	struct node* next;
}node;

typedef struct stack_type {
	node* top;
	Item pop_val; 
}stack_type;


PUBLIC Stack stack_create() {
	
	Stack s = (Stack)malloc(sizeof(stack_type));

	assert(s != NULL);

	s->top = NULL;

	return s;
}

PUBLIC void stack_destory(Stack s) {
	
	stack_make_empty(s);
	free(s);
}



PUBLIC void stack_make_empty(Stack s) {
	while (!stack_is_empty(s))
		stack_pop(s);
}

PUBLIC bool stack_is_empty(Stack s) {
	return s->top == NULL;
}

PUBLIC bool stack_is_full(Stack s) {
	return false;
}

PUBLIC bool stack_push(Stack s, Item i) {

	node* new_node = (node*)malloc(sizeof(node));
	if (new_node == NULL)
		return false;
	
	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;

	return true;
}

PUBLIC Item* stack_pop(Stack s) {

	if (stack_is_empty(s))
		return NULL;

	node* del = s->top;
	s->pop_val = del->data;
	s->top = s->top->next;
	free(del);

	return &s->pop_val;
}
