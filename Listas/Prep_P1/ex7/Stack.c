#include <stdlib.h>
#include "Stack.h"

struct element {
  int data;
  struct element* prev;
};

typedef struct element Elem;

struct stack {
  int count;
  Elem *top;
};

Stack* create_stack() {
  Stack* stk = (Stack*) malloc(sizeof(Stack));
  if (stk != NULL) {
    stk->top = NULL;
    stk->count = 0;
  }
  return stk;
}

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
  return stk->count;
}

int empty_stack(Stack* stk) {
  if (stk == NULL) return -1;
  if (stk->top == NULL) return 1;
  return 0;
}

int push(Stack* stk, int value) {
  if (stk == NULL) return 0;

  Elem *no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return 0;

  no->data = value;
  no->prev = stk->top;
  stk->top = no;
  stk->count++;
  return 1;
}

int pop(Stack* stk, int *value) {
  if (stk == NULL || empty_stack(stk)) return 0;
  Elem* no = stk->top; // Aponta para o top do stack
  stk->top = no->prev; // Atualiza top do stack para seu antecessor
  *value = no->data; // Passa como ponteiro o valor do top que foi desempilhado
  free(no); // Libera o top antigo
  stk->count--;
  return 1;
}

int top(Stack* stk, int *value) {
  if (stk == NULL || empty_stack(stk)) return 0;
  *value = stk->top->data;
  return 1;
}
