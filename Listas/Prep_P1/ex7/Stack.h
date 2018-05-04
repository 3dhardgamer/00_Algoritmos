/* Dynamic (linked) stack */

#ifndef _STACK_H_
#define _STACK_H_

typedef struct element elem;
struct element {
  int data;
  struct element *prev;
};

typedef struct stack stack;
struct stack {
  int count;
  struct element *top;
};


// stack creation and deletion functions:
stack* stack_create();
void stack_delete(stack* stk);

// stack inspection functions:
int stack_size(stack* stk);
int stack_full(stack* stk);
int stack_empty(stack* stk);

// stack standard functions:
void stack_push(stack* stk, int value);
int stack_pop(stack* stk);
int stack_top(stack* stk);

#endif
