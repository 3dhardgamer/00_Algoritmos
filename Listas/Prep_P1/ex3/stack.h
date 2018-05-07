/* Dynamic (linked) stack */

#ifndef _STACK_H_
#define _STACK_H_

typedef struct element elem;
struct element {
  int data;
  elem *prev;
};

typedef struct stack stack;
struct stack {
  int count;
  elem *top;
};


// stack creation and deletion functions:
stack* stack_create();
void stack_delete(stack* stk);

// stack inspection functions:
int stack_size(stack* stk);

// stack standard functions:
void stack_push(stack* stk, int value);
int stack_pop(stack* stk);
int stack_peek(stack* stk);

#endif
