#include <stdio.h>
#include "queue.h"

int main() {
  queue* qe = queue_create();

  queue_enqueue(qe, 1);
  queue_enqueue(qe, 2);
  queue_enqueue(qe, 3);
  printf("%d %d %d\n", queue_dequeue(qe), queue_dequeue(qe), queue_dequeue(qe));

  queue_enqueue(qe, 4);
  queue_enqueue(qe, 5);
  queue_enqueue(qe, 6);
  printf("%d\n", queue_peek(qe));

  queue_delete(qe);

  return 0;
}

