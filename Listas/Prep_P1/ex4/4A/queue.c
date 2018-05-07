#include <stdlib.h>
#include "queue.h"

queue* queue_create() {
  queue* qe = malloc(sizeof (queue));
  qe->begin = 0;
  qe->end = 0;
  qe->count = 0;
  return qe;
}

void queue_delete(queue* qe) {
  free(qe);
}

int queue_size(queue* qe) {
  return qe->count;
}

void queue_enqueue(queue* qe, int value) {
  qe->data[qe->end] = value;
  qe->end = (qe->end + 1) % MAXN;
  qe->count++;
}

int queue_dequeue(queue* qe) {
  int value = qe->data[qe->begin];
  qe->begin = (qe->begin + 1) % MAXN;
  qe->count--;
  return value;
}

int queue_peek(queue* qe) {
  return qe->data[qe->begin];
}
