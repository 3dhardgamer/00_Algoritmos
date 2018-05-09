#include <stdio.h>
#include "stack.h"

void stack_sort(stack* stk) {
  stack *stk_aux = stack_create();
  int temp;

  // while the main stack have elements each one will be
  // compared element on the top of the auxiliary stack
  while (stk->count > 0) {
    // temp value correspond to current main stack top
    // temp value is compared to auxiliary stack values
    temp = stack_pop(stk);

    // If the value on top of auxiliary stack is greater than temp
    // pop the value back to main stack
    while (stk_aux->count > 0 && stack_peek(stk_aux) > temp)
      stack_push(stk, stack_pop(stk_aux));

    // do this up to the point when the auxiliary stack has smaller value
    // then push temp above on auxiliary stack
    stack_push(stk_aux, temp);
  }

  // once the highest number are on the top of auxiliary stack the stack is decreasing
  // pop from auxiliary and push to main to have an increasing order
  while (stk_aux->count > 0)
    stack_push(stk, stack_pop(stk_aux));

  stack_delete(stk_aux);
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

  stack_push(stk, 10);
  stack_push(stk, 82);
  stack_push(stk, 76);
  stack_push(stk, 21);
  stack_push(stk, 254);
  stack_push(stk, 3);
  stack_push(stk, 2);
  stack_sort(stk);
  while (stk->count > 0)
    printf("%d\n", stack_pop(stk));


  stack_delete(stk);
  return 0;
}
