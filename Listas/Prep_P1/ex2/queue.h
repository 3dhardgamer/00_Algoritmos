#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct element elem;
struct element {
  int data;
  elem* next;
};

typedef struct queue queue;
struct queue {
  int count;
  elem *begin;
  elem *end;
};

queue* queue_create();
void queue_delete(queue* qe);
int queue_size(queue* qe);
void queue_enqueue(queue* qe, int value); // Insert at the end of the queue
int queue_dequeue(queue* qe); // Remove from the beginning of the queue
int queue_peek(queue* qe); // Look at the front of the queue

#endif
