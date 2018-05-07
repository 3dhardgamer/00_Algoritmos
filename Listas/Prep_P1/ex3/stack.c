#include <stdlib.h>
#include "stack.h"

stack* stack_create() {
  stack* stk = malloc(sizeof (stack)); // sizeof precisa de parenteses pq e um tipo e nao ponteiro do tipo
  if (stk != NULL) {
    stk->top = NULL;
    stk->count = 0;
  }
  return stk;
}

void stack_delete(stack* stk) {
  if (stk != NULL) {
    elem* no;
    while (stk->top != NULL) {
      no = stk->top;
      stk->top = stk->top->prev;
      free(no);
    }
    free(stk);
  }
}

int stack_size(stack* stk) {
  return stk->count;
}

void stack_push(stack* stk, int value) {
  elem *no = malloc(sizeof(elem));

  no->data = value;
  no->prev = stk->top;
  stk->top = no;
  stk->count++;
}

int stack_pop(stack* stk) {
  int value;
  elem* no = stk->top; // Aponta para o top do stack
  stk->top = no->prev; // Atualiza top do stack para seu antecessor
  value = no->data;
  free(no); // Libera o top antigo
  stk->count--;
  return value;
}

int stack_top(stack* stk) {
  return stk->top->data;
}
