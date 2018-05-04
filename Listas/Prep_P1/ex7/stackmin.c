#include <stdlib.h>
#include "stack.h"
#include "stackmin.h"

stackmin* stackmin_create() {
  stackmin* stkmin = malloc(sizeof(stackmin));

  stkmin->def = stack_create();
  stkmin->aux = stack_create();

  return stkmin;
}

void stackmin_delete(stackmin* stkmin) {
  stack_delete(stkmin->def);
  stack_delete(stkmin->aux);
  free(stkmin);
}

void stackmin_push(stackmin* stkmin, int value) {
  stack_push(stkmin->def, value);
  if (stkmin->aux->top == NULL || value < stkmin->aux->top->data)
    stack_push(stkmin->aux, value);
}

int stackmin_pop(stackmin* stkmin) {
  int value;
  value = stack_pop(stkmin->def);
  if (value == stkmin->aux->top->data)
    stack_pop(stkmin->aux);

  return value;
}

int stackmin_top(stackmin* stkmin) {
  return stack_top(stkmin->def);
}

int stackmin_min(stackmin* stkmin) {
  return stack_top(stkmin->aux);
}
