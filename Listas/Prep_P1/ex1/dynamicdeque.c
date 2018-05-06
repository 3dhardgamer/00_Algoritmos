#include <stdlib.h>
#include "dynamicdeque.h"

deque* deque_create() {
  deque* dq = malloc(sizeof (deque));
  if (dq != NULL) {
    dq->begin = NULL;
    dq->end = NULL;
    dq->count = 0;
  }
  return dq;
}

void deque_delete(deque* dq) {
  if (dq != NULL) {
    elem* no;
    while (dq->begin != NULL) {
      no = dq->begin;
      dq->begin = no->next;
      free(no);
    }
    free(dq);
  }
}

int deque_size(deque* dq) {
  return dq->count;
}

void deque_push_begin(deque* dq, int value) {
  elem* no = malloc(sizeof (elem));

  no->data = value;
  no->prev = NULL;
  no->next = dq->begin;

  if (dq->begin == NULL)
    dq->end = no;
  else
    dq->begin->prev = no;

  dq->begin = no;
  dq->count++;
}

void deque_push_end(deque* dq, int value) {
  elem* no = malloc(sizeof (elem));

  no->data = value;
  no->next = NULL;

  if (dq->end == NULL) {
    no->prev = NULL;
    dq->begin = no;
  }
  else {
    no->prev = dq->end;
    dq->end->next = no;
  }

  dq->end = no;
  dq->count++;
}

int deque_pop_begin(deque* dq) {
  int value;
  elem* no = dq->begin;
  dq->begin = no->next;
  if (dq->begin == NULL)
    dq->end = NULL;
  else
    dq->begin->prev = NULL;

  value = no->data;
  free(no);
  dq->count--;
  return value;
}

int deque_pop_end(deque* dq) {
  int value;
  elem* no = dq->end;
  if (no == dq->begin) {
    dq->begin = NULL;
    dq->end = NULL;
  }
  else {
    no->prev->next = NULL;
    dq->end = NULL;
  }

  value = no->data;
  free(no);
  dq->count--;
  return value;
}

int deque_peek_begin(deque* dq) {
  return dq->begin->data;
}

int deque_peek_end(deque* dq) {
  return dq->end->data;
}
