#include <ctype.h>
#include "rpn_calculator.h"

int rpn_calculate(char* exp) {
  stack* stk = stack_create();
  int i;

  for (i = 0; exp[i]; i++) {
    if (isdigit(exp[i]))
      stack_push(stk, exp[i] - '0'); // convert char to int

    else {
      switch (exp[i]) {
        case '+':
          stack_push(stk, addition(stack_pop(stk), stack_pop(stk)));
          break;
        case '-':
          stack_push(stk, subtraction(stack_pop(stk), stack_pop(stk)));
          break;
        case '*':
          stack_push(stk, multiplication(stack_pop(stk), stack_pop(stk)));
          break;
        case '/':
          stack_push(stk, division(stack_pop(stk), stack_pop(stk)));
          break;
      }
    }
  }

  return stack_pop(stk);
}

int addition(int val1, int val2) {
  return val1 + val2;
}

int subtraction(int val1, int val2) {
  return val2 - val1;
}

int multiplication(int val1, int val2) {
  return val1 * val2;
}

int division(int val1, int val2) {
  return val2 / val1;
}
