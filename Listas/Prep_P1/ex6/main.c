#include <stdio.h>
#include "stacknew.h"

int main() {
  stacknew* stkn = stacknew_create();

  stacknew_push(stkn, 1);
  stacknew_push(stkn, 2);
  stacknew_push(stkn, 3);
  stacknew_push(stkn, 4);
  stacknew_push(stkn, 5);
  for (int i = 0; i < 5; i++)
    printf("%d\n", stacknew_pop(stkn));

  stacknew_push(stkn, 1);
  stacknew_push(stkn, 2);
  stacknew_push(stkn, 3);
  stacknew_push(stkn, 4);
  stacknew_push(stkn, 5);
  stacknew_reverse(stkn);
  for (int i = 0; i < 5; i++)
    printf("%d\n", stacknew_pop(stkn));

  stacknew_delete(stkn);
  return 0;
}

