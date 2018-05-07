#include <stdlib.h>
#include "queue.h"

queue* queue_create() {
  queue* qe = malloc(sizeof (queue));
  qe->def = stack_create();
  qe->aux = stack_create();
  return qe;
}

void queue_delete(queue* qe) {
  stack_delete(qe->def);
  stack_delete(qe->aux);
  free(qe);
}

int queue_size(queue* qe) {
  return qe->def->count;
}

void queue_enqueue(queue* qe, int value) {
  stack_push(qe->def, value);
}

int queue_dequeue(queue* qe) {
  int value;
  while (qe->def->count != 1)
    stack_push(qe->aux, stack_pop(qe->def));

  value = stack_pop(qe->def);
  while (qe->aux->count > 0)
    stack_push(qe->def, stack_pop(qe->aux));

  return value;
}

int queue_peek(queue* qe) {
  int value;
  while (qe->def->count != 1)
    stack_push(qe->aux, stack_pop(qe->def));

  value = stack_peek(qe->def);
  while (qe->aux->count > 0)
    stack_push(qe->def, stack_pop(qe->aux));

  return value;
}
