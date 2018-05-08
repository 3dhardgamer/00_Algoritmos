#include <stdio.h>
#include <stdlib.h>
#include "rpn_calculator.h"


int main() {
  char exp[] = "5 1 2 + 4 * + 3 -";
  int res;
  res = rpn_calculate(exp);
  printf("%d\n", res);

  return 0;
}

