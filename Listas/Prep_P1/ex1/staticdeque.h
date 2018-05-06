/* STATIC DEQUE */

#ifndef _STATICDEQUE_H_
#define _STATICDEQUE_H_

#define MAXN 100

typedef struct deque deque;

struct deque {
  int begin, end, count;
  int data[MAXN];
};

deque* deque_create();
void deque_delete(deque* dq);
int deque_size(deque* dq);
void deque_push_begin(deque* dq, int value);
void deque_push_end(deque* dq, int value);
int deque_pop_begin(deque* dq);
int deque_pop_end(deque* dq);
int deque_peek_begin(deque* dq);
int deque_peek_end(deque* dq);

#endif
