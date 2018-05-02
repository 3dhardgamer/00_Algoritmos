#include <stdlib.h>
#include "Stack.h"

struct element {
  char data;
  struct element* prev;
};

typedef struct element Elem;

struct stack {
  int qtd;
  Elem *menor;
  Elem *top;
};

Stack* create_stack() {
  Stack* stk = (Stack*) malloc(sizeof(Stack));
  if (stk != NULL) {
    stk->menor = NULL;
    stk->top = NULL;
    stk->qtd = 0;
  }
  return stk;
}

/*
int is_valid(Stack* stk) {
  if (stk == NULL) return 0;
  return 1;
}
*/

void delete_stack(Stack* stk) {
  if (stk != NULL) {
    Elem* no;
    while (stk->top != NULL) {
      no = stk->top;
      stk->top = stk->top->prev;
      free(no);
    }
    free(stk);
  }
}

int stack_size(Stack* stk) {
  if (stk == NULL) return 0;
  return stk->qtd;
}

int empty_stack(Stack* stk) {
  if (stk == NULL) return -1;
  if (stk->top == NULL) return 1;
  return 0;
}

