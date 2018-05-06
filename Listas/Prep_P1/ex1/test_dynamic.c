#include <stdio.h>
#include "staticdeque.h"

int main() {
  deque* dq = deque_create();

  deque_push_begin(dq, 1);
  deque_push_begin(dq, 2);
  deque_push_end(dq, 3);

  printf("%d %d %d\n", deque_pop_begin(dq), deque_pop_begin(dq), deque_pop_begin(dq));

  deque_delete(dq);


  return 0;
}
