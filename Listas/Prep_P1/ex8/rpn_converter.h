#ifndef _RPN_CONVERTER_H_
#define _RPN_CONVERTER_H_

#include "stack.h"

int is_operand(char ch);
int precedence(char ch);
void rpn_convert(char* exp);

#endif
