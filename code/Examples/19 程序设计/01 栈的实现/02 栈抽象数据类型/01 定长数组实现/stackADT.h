#ifndef STACKADT_H
#define STACKADT_H

#include<stdbool.h>

typedef struct stack_type* Stack;

Stack create();
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(const Stack s);
bool is_full(const Stack s);
void push(Stack s, int i);
int pop(Stack s);

#endif