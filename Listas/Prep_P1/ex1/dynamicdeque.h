/* DYNAMIC DEQUE */

#ifndef _DYNAMICDEQUE_H_
#define _DYNAMICDEQUE_H_

typedef struct element elem;
struct element {
  elem *prev;
  elem *next;
  int data;
};

typedef struct deque deque;
struct deque {
  elem *begin;
  elem *end;
  int count;
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
