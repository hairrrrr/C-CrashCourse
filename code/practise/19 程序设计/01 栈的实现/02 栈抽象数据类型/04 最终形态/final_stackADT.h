#ifndef FINAL_STACKADT_H
#define FINAL_STACKADT_H

#include<stdbool.h>

typedef int Item;

typedef struct stack_type* Stack;

Stack stack_create();
void stack_destory(Stack s);
void stack_make_empty(Stack s);
bool stack_is_empty(const Stack s);
bool stack_is_full(const Stack s);
bool stack_push(Stack s, Item i);
Item* stack_pop(Stack s);

#endif