#include <stdlib.h>
#include "queue.h"

queue* queue_create() {
  queue* qe = malloc(sizeof (queue));
  if (qe != NULL) {
    qe->begin = NULL;
    qe->end = NULL;
    qe->count = 0;
  }
  return qe;
}

void queue_delete(queue* qe) {
  if (qe != NULL) {
    elem* no;
    while (qe->begin != NULL) {
      no = qe->begin;
      qe->begin = no->next;
      free(no);
    }
    free(qe);
  }
}

int queue_size(queue* qe) {
  return qe->count;
}

void queue_enqueue(queue* qe, int value) {
  elem* no = malloc(sizeof (elem));
  no->data = value;
  no->next = NULL;

  if (qe->end == NULL)
    qe->begin = no;
  else
    qe->end->next = no;

  qe->end = no;
  qe->count++;
}

char queue_dequeue(queue* qe) {
  int value = qe->begin->data;

  elem* no = qe->begin;
  qe->begin = no->next;

  if (qe->begin == NULL)
    qe->end = NULL;

  free(no);
  qe->count--;
  return value;
}

char queue_peek(queue* qe) {
  return qe->begin->data;
}
