#include <stdlib.h>
#include "OrderedQueue.h"

struct element {
  int value;
  struct element *next;
};

typedef struct element Elem;

struct queue {
  struct element *begin;
  struct element *end;
  int count;
};

Queue* create_queue() {
  Queue* qe = (Queue*) malloc(sizeof(Queue));
  if (qe != NULL) {
    qe->begin = NULL;
    qe->end = NULL;
    qe->count = 0;
  }
  return qe;
}

void delete_queue(Queue* qe) {
  if (qe != NULL) {
    Elem* no;
    while (qe->begin != NULL) {
      no = qe->begin;
      qe->begin = qe->begin->next;
      free(no);
    }
    free(qe);
  }
}

int queue_size(Queue* qe) {
  if (qe == NULL) return 0;
  return qe->count;
}

int full_queue(Queue* qe) {
  return 0;
}

int empty_queue(Queue* qe) {
  if (qe == NULL) return -1;
  if (qe->begin == NULL) return 1;
  return 0;
}

int enqueue(Queue* qe) {}

