#include <stdio.h>
#include "stack.h"

stack* stack_create() {
  stack* stk = malloc(sizeof (stack));
  stk->def = queue_create();
  stk->aux = queue_create();
  return stk;
}

void stack_delete(stack* stk) {
  queue_delete(stk->def);
  queue_delete(stk->aux);
  free(stk);
}

int stack_size(stack* stk) {
  return stk->def->count;
}

void stack_push(stack* stk, int value) {
  queue_enqueue(stk->def, value);
}

int stack_pop(stack* stk) {
  int value;
  // Desempilha os elementos de stk->def até sobrar o que está mais baixo na pilha
  // Empilha os elemento na stk->aux
  while (stk->def->count != 1)
    queue_enqueue(stk->aux, queue_dequeue(stk->def));

  // value recebe o valor do elemento que está mais baixo na pilha
  value = queue_dequeue(stk->def);
  // Desempilha a stk->aux e e empilha na stk->def (devolve os elementos para pilha principal)
  while (stk->aux != NULL)
    queue_enqueue(stk->def, queue_dequeue(stk->aux));

  return value;
}

int stack_peek(stack* stk) {
  int value;
  while (stk->def->count != 1)
    queue_enqueue(stk->aux, queue_dequeue(stk->def));

  // Ao invés de desempilhar, apenas olha o elemento
  value = queue_peek(stk->def);
  while (stk->aux != NULL)
    queue_enqueue(stk->def, queue_dequeue(stk->aux));

  return value;
}
