#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

void check_control(FILE* arq) {
  queue* qe = queue_create();
  char entry;
  int valin, valqe;
  int N;
  fscanf(arq, "%d\n", &N);

  for (int i = 0; i < N; i++) {
    fscanf(arq, "%c %d ", &entry, &valin);

    if (entry == 'E')
      queue_enqueue(qe, valin);

    else {
      valqe = queue_dequeue(qe);
      printf("%d %d\n", valqe, valin);
    }
  }
  queue_delete(qe);
}


int main() {
  FILE *arq;
  arq = fopen("entrada.txt", "r");

  check_control(arq);

  fclose(arq);

  return 0;
}
