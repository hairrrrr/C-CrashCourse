#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"stackADT.h"

int main(void) {

	Stack s1, s2;

	s1 = create();
	s2 = create();

	push(s1, 1);
	push(s1, 2);
	
	printf("%d\n", pop(s1));
	printf("%d\n", pop(s1));

	destory(s1);
	destory(s2);

		return 0;
}
