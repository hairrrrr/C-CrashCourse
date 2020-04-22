#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"final_stackADT.h"

int main(void) {

	Stack s1, s2;

	s1 = stack_create();
	s2 = stack_create();

	stack_push(s1, 1);
	stack_push(s1, 2);
	
	printf("%d\n", *stack_pop(s1));
	printf("%d\n", *stack_pop(s1));

	stack_destory(s1);
	stack_destory(s2);

		return 0;
}



