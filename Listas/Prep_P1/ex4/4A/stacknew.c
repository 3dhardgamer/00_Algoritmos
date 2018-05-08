#include <stdlib.h>
#include "stacknew.h"

stacknew* stacknew_create() {
  stacknew* stkn = malloc(sizeof (stacknew));
  stkn->def = stack_create();
  stkn->aux = queue_create();
  return stkn;
}

void stacknew_delete(stacknew* stkn) {
  stack_delete(stkn->def);
  queue_delete(stkn->aux);
  free(stkn);
}

int stacknew_size(stacknew* stkn) {
  return stkn->def->count;
}

void stacknew_push(stacknew* stkn, int value) {
  stack_push(stkn->def, value);
}

int stacknew_pop(stacknew* stkn) {
  return stack_pop(stkn->def);
}

int stacknew_peek(stacknew* stkn) {
  return stack_peek(stkn->def);
}

void stacknew_reverse(stacknew* stkn) {
  // desempilha para uma fila
  while (stkn->def->count > 0)
    queue_enqueue(stkn->aux, stack_pop(stkn->def));

  // desenfileira de volta para a pilha
  while (stkn->aux->count > 0)
    stack_push(stkn->def, queue_dequeue(stkn->aux));
}

