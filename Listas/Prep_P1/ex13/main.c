#include <stdio.h>
#include "queue.h"

int check_control(char* linebuffer, int N) {
  queue* qe = queue_create();

  char p, t;
  int res;

  for (int i = 1; i <= N; i++) {
    p = linebuffer[i];
    t = linebuffer[i + 1];

    if (p == '(') {
      queue_enqueue(qe, p);
      queue_enqueue(qe, t);
    }
    else if (p == ')') {
      if (t == queue_peek(qe)) {
        queue_dequeue(qe);
        queue_dequeue(qe);
      }
      else {
        return -1;
      }
    }
  }
  res = qe->count;
  queue_delete(qe);
  queue_delete(qe);

  return res;
}

int main() {
  char linebuffer[4096];
  int res;
  fgets(linebuffer, sizeof(linebuffer), stdin);
  
  return 0;
}
