#include <stdlib.h>
#include "stack.h"

stack* stack_create() {
  stack* stk = malloc(sizeof (stack));
  stk->count = 0;
  return stk;
}

void stack_delete(stack* stk) {
  free(stk);
}

int stack_size(stack* stk) {
  return stk->count;
}

void stack_push(stack* stk, char value) {
  stk->data[stk->count] = value;
  stk->count++;
}

int stack_pop(stack* stk) {
  int value = stk->data[stk->count - 1];
  stk->count--;
  return value;
}

int stack_peek(stack* stk) {
  return stk->data[stk->count - 1];
}

