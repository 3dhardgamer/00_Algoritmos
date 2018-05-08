#include <stdio.h>
#include <stdlib.h>
#include "rpn_converter.h"


// Check if the next in the expression is an operand
int is_operand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// each operator has a diffent priority value
// the higher the value the higher it's priority
int priority(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  if (ch == '*' || ch == '/' || ch == '%')
    return 2;
  if (ch == '^')
    return 3;

  return -1;
}

// conversion of infix to postfix notation
void rpn_convert(char* exp) {
  int i, k;
  // creates auxiliary stack to hold operators
  stack* stk = stack_create();

  // using the same expression char scan the element and replace it on the output
  for (i = 0, k = -1; exp[i]; i++) {
    // If the element of the expression is an operando, add to output
    if (is_operand(exp[i]))
      exp[++k] = exp[i];

    // push to stack non operand characters
    else if (exp[i] == '(')
      stack_push(stk, exp[i]);

    // pop character from stack if parenthesis is closed ')'
    else if (exp[i] == ')') {
      // pop untill find a new open parenthesis '('
      while (stk->count > 0 && stack_peek(stk) != '(')
        exp[++k] = stack_pop(stk);

      // in case the expression is in valid, wrong parenthesis alignment
      if (stk->count > 0 && stack_peek(stk) != '(')
        return;
      else
        stack_pop(stk);
    }

    // check operator priority
    // if low priority, it is added to output straight away
    else {
      while (stk->count > 0 && priority(exp[i]) <= priority(stack_peek(stk)))
        exp[++k] = stack_pop(stk);

      stack_push(stk, exp[i]);
    }

  }

  while (stk->count > 0)
    exp[++k] = stack_pop(stk);

  stack_delete(stk);
  exp[++k] = '\0';
  printf("%s\n", exp);
}
