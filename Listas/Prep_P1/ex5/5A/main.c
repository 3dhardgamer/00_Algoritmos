#include <stdio.h>
#include "queuenew.h"

int main() {
  queuenew* stkn = queuenew_create();

  queuenew_enqueue(stkn, 1);
  queuenew_enqueue(stkn, 2);
  queuenew_enqueue(stkn, 3);
  queuenew_enqueue(stkn, 4);
  queuenew_enqueue(stkn, 5);
  for (int i = 0; i < 5; i++)
    printf("%d\n", queuenew_dequeue(stkn));

  queuenew_enqueue(stkn, 1);
  queuenew_enqueue(stkn, 2);
  queuenew_enqueue(stkn, 3);
  queuenew_enqueue(stkn, 4);
  queuenew_enqueue(stkn, 5);
  queuenew_reverse(stkn);
  for (int i = 0; i < 5; i++)
    printf("%d\n", queuenew_dequeue(stkn));

  queuenew_delete(stkn);
  return 0;
}

