#include <stdio.h>
#include <stdlib.h>
#include "rpn_converter.h"


int main() {
  char exp[] = "((A+B)*(C-D))";
  rpn_convert(exp);

  return 0;
}

