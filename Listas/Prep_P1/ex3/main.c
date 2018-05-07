#include <stdio.h>
#include "queue.h"

int main() {
  queue* qe = queue_create();

  queue_enqueue(qe, 1);
  queue_enqueue(qe, 2);
  queue_enqueue(qe, 3);
  printf("%d %d %d\n", queue_dequeue(qe), queue_dequeue(qe), queue_dequeue(qe));
  queue_delete(qe);

  return 0;
}

