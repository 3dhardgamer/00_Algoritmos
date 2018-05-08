#include <stdlib.h>
#include "stacknew.h"

stacknew* stacknew_create() {
  stacknew* stkn = malloc(sizeof (stacknew));
  stkn->def = stack_create();
  stkn->aux1 = stack_create();
  stkn->aux2 = stack_create();
  return stkn;
}

void stacknew_delete(stacknew* stkn) {
  stack_delete(stkn->def);
  stack_delete(stkn->aux1);
  stack_delete(stkn->aux2);
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
  // desempilha para primeira pilha auxiliar
  while (stkn->def->count > 0)
    stack_push(stkn->aux1, stack_pop(stkn->def));

  // desempilha para a segunda pilha auxiliar
  while (stkn->aux1->count > 0)
    stack_push(stkn->aux2, stack_pop(stkn->aux1));

  // desempilha para a pilha principal na ordem inversa
  while (stkn->aux2->count > 0)
    stack_push(stkn->def, stack_pop(stkn->aux2));
}

