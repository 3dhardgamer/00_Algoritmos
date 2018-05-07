#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAXN 100

typedef struct queue queue;
struct queue {
  int begin, end, count;
  int data[MAXN];
};

queue* queue_create();
void queue_delete(queue* qe);
int queue_size(queue* qe);
void queue_enqueue(queue* qe, int value);
int queue_dequeue(queue* qe);
int queue_peek(queue* qe);

#endif
