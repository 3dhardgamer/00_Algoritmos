#ifndef _STACKNEW_H_
#define _STACKNEW_H_

#include "stack.h"
#include "queue.h"

typedef struct stacknew stacknew;
struct stacknew {
  stack* def;
  queue* aux;
};

stacknew* stacknew_create();
void stacknew_delete(stacknew* stkn);
int stacknew_size(stacknew* stkn);
void stacknew_push(stacknew* stkn, int value);
int stacknew_pop(stacknew* stkn);
int stacknew_peek(stacknew* stkn);

void stacknew_reverse(stacknew* stkn);

#endif
