#ifndef _RPN_CONVERTER_H_
#define _RPN_CONVERTER_H_

#include "stack.h"

int is_operand(char ch);
int priority(char ch);
void rpn_convert(char* exp);

#endif
