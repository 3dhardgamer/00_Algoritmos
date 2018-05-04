#include <stdio.h>
#include "stack.h"
#include "stackmin.h"

int main() {
  stackmin* stkmin = stackmin_create();

  int num[] = {30, 23, 42, 1, -2, 4};

  for (int i = 0; i < 6; i++) {
    stackmin_push(stkmin, num[i]);
    printf("%d --- %d\n", stackmin_top(stkmin), stackmin_min(stkmin));
  }
  printf("\n\n\n");
  for (int i = 0; i < 5; i++) {
    printf("%d --- %d\n", stackmin_pop(stkmin), stackmin_min(stkmin));
  }




  return 0;
}
