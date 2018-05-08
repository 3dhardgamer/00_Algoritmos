#include <stdio.h>
#include <stdlib.h>
#include "rpn_converter.h"

int is_operand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
  if (ch == '(')
    return 0;
  if (ch == '+' || ch == '-')
    return 1;
  if (ch == '*' || ch == '/' || ch == '%')
    return 2;
  if (ch == '^')
    return 3;

  return -1;
}

void rpn_convert(char* exp) {
  int i, k;
  stack* stk = stack_create();
  if (stk == NULL)
    return;

  for (i = 0, k = -1; exp[i]; i++) {
    if (is_operand(exp[i]))
      exp[++k] = exp[i];

    else if (exp[i] == '(')
      stack_push(stk, exp[i]);

    else if (exp[i] == ')') {
      while (stk->count > 0 && stack_peek(stk) != '(')
        exp[++k] = stack_pop(stk);

      if (stk->count > 0 && stack_peek(stk) != '(')
        return;
      else
        stack_pop(stk);
    }
    else {
      while (stk->count > 0 && precedence(exp[i]) <= precedence(stack_peek(stk)))
        exp[++k] = stack_pop(stk);

      stack_push(stk, exp[i]);
    }

  }

  while (stk->count > 0)
    exp[++k] = stack_pop(stk);

  exp[++k] = '\0';
  printf("%s\n", exp);
}
