#include <stdio.h>
#include "stack.h"

void stack_sort(stack* stk) {
  stack *stktemp = stack_create();
  int temp;

  while (stk->count > 0) {
    temp = stack_pop(stk);

    while (stktemp->count > 0 && stack_peek(stktemp) > temp) 
      stack_push(stk, stack_pop(stktemp));

    stack_push(stktemp, temp);
  }

  while (stktemp->count > 0)
    stack_push(stk, stack_pop(stktemp));

  stack_delete(stktemp);
}

int main() {
  stack* stk = stack_create();

  stack_push(stk, 10);
  stack_push(stk, 82);
  stack_push(stk, 76);
  stack_push(stk, 21);
  stack_push(stk, 254);
  stack_push(stk, 3);
  stack_push(stk, 2);
  while (stk->count > 0)
    printf("%d\n", stack_pop(stk));

  stack_delete(stk);
  return 0;
}
