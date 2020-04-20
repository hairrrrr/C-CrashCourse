#ifndef STACK_H
#define STACK_H

#include<stdbool.h> //C99 only

void make_empty();
bool is_empty();
bool is_full();
void push(int i);
int pop();

#endif
