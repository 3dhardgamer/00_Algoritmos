#include <stdlib.h>
#include "queuenew.h"

queuenew* queuenew_create() {
  queuenew* qen = malloc(sizeof (queuenew));
  qen->def = queue_create();
  qen->aux = stack_create();
  return qen;
}

void queuenew_delete(queuenew* qen) {
  queue_delete(qen->def);
  stack_delete(qen->aux);
  free(qen);
}

int queuenew_size(queuenew* qen) {
  return qen->def->count;
}

void queuenew_enqueue(queuenew* qen, int value) {
  queue_enqueue(qen->def, value);
}

int queuenew_dequeue(queuenew* qen) {
  return queue_dequeue(qen->def);
}

int queuenew_peek(queuenew* qen) {
  return queue_peek(qen->def);
}

void queuenew_reverse(queuenew* qen) {
  while (qen->def->count > 0)
    stack_push(qen->aux, queue_dequeue(qen->def));

  while (qen->aux->count > 0)
    queue_enqueue(qen->def, stack_pop(qen->aux));
}


