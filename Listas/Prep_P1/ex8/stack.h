#ifndef _STACK_H_
#define _STACK_H_

#define MAXN 10000

typedef struct stack stack;
struct stack {
  int count;
  char data[MAXN];
};

stack* stack_create();
void stack_delete(stack* stk);
int stack_size(stack* stk);
void stack_push(stack* stk, char value);
char stack_pop(stack* stk);
char stack_peek(stack* stk);

#endif
