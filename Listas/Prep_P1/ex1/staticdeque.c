/* STATIC DEQUE */
#include <stdlib.h>
#include "staticdeque.h"

deque* deque_create() {
  deque* dq = malloc(sizeof(deque));
  dq->begin = 0;
  dq->end = 0;
  dq->count = 0;

  return dq;
}

void deque_detele(deque* dq) {
  free(dq);
}

int deque_size(deque* dq) {
  return dq->count;
}

void deque_push_begin(deque* dq, int value) {
  dq->begin--;
  if (dq->begin < 0)
    dq->begin = MAXN - 1;

  dq->data[dq->begin] = value;
  dq->count++;
}

void deque_push_end(deque* dq, int value) {
  dq->data[dq->end] = value;
  dq->end = (dq->end + 1) % MAXN;
  dq->count++;
}

int deque_pop_begin(deque* dq) {
  int value;
  value = dq->data[dq->begin];

  dq->begin = (dq->begin + 1) % MAXN;
  dq->count--;

  return value;
}

int deque_pop_end(deque* dq) {
  int value;
  value = dq->data[dq->end];

  dq->end--;
  if (dq->end < 0)
    dq->end = MAXN - 1;

  dq->count--;

  return value;
}

int deque_peek_begin(deque* dq) {
  return dq->data[dq->begin];
}

int deque_peek_end(deque* dq) {
  return dq->data[dq->end];
}
