#ifndef _QUEUENEW_H_
#define _QUEUENEW_H_

#include "queue.h"
#include "stack.h"

typedef struct queuenew queuenew;
struct queuenew {
  queue* def;
  stack* aux;
};

queuenew* queuenew_create();
void queuenew_delete(queuenew* qen);
int queuenew_size(queuenew* qen);
void queuenew_enqueue(queuenew* qen, int value);
int queuenew_dequeue(queuenew* qen);
int queuenew_peek(queuenew* qen);

void queuenew_reverse(queuenew* qen);

#endif
