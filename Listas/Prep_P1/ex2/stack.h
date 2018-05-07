#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include "queue.h"

typedef struct stack stack;
struct stack {
  queue *def;
  queue *aux;
};

stack* stack_create();
void stack_delete(stack* stk);
int stack_size(stack* stk);
void stack_push(stack* stk, int value);
int stack_pop(stack* stk);
int stack_peek(stack* stk);

#endif
