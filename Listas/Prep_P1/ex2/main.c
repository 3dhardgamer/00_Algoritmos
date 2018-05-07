#include <stdio.h>
#include "stack.h"

int main() {
  stack* stk = stack_create();

  stack_push(stk, 1);
  stack_push(stk, 2);
  stack_push(stk, 3);
  printf("%d %d %d\n", stack_pop(stk), stack_pop(stk), stack_pop(stk));

  stack_delete(stk);
  return 0;
}

