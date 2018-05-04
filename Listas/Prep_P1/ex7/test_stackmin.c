#include <stdio.h>
#include "stack.h"
#include "stackmin.h"

int main() {
  stackmin* stkmin = stackmin_create();

  stackmin_push(stkmin, 5);
  stackmin_push(stkmin, 3);
  stackmin_push(stkmin, 2);
  stackmin_push(stkmin, 4);
  stackmin_push(stkmin, 6);
  for (int i = 0; i < 3; i++) 
    printf("%d\n", stackmin_pop(stkmin));



  return 0;
}
