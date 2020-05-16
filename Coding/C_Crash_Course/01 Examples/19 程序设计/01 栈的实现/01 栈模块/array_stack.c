#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

#define STACK_SIZE 100

static int contents[STACK_SIZE];
static int top = 0;

static void terminate(const char* message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void make_empty() {
	top = 0;
}

bool is_empty() {
	return top == 0;
}

bool is_full() {
	return top == STACK_SIZE;
}

void push(int i) {
	if (is_full())
		terminate("Error in push: stack is full\n");
	contents[top++] = i;
}

int pop() {
	if (is_empty())
		printf("Error in pop: stack is empty\n");
	return contents[--top];
}

