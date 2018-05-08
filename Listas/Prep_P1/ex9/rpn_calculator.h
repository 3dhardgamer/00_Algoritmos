#ifndef _RPN_CALCULATOR_H_
#define _RPN_CALCULATOR_H_

#include <stdlib.h>
#include "stack.h"

int rpn_calculate(char* exp);
int addition(int val1, int val2);
int subtraction(int val1, int val2);
int multiplication(int val1, int val2);
int division(int val1, int val2);

#endif

