#include <stdlib.h>
#include "StaticDeque.h"

struct deque {
  int begin, end, qtd;
  int data[MAXN];
};

Deque* create_deque() {
  Deque* dq = (Deque*) malloc(sizeof(Deque));
  if (dq != NULL) {
    dq->begin = 0;
    dq->end = 0;
    dq->qtd = 0;
  }
  return dq;
}

void delete_deque(Deque* dq) {
  free(dq);
}

int is_valid(Deque* dq) {
  return (dq == NULL);
}

int deque_size(Deque* dq) {
  if (is_valid(dq)) return -1;
  else return dq->qtd;
}

int full_deque(Deque* dq) {
  if (is_valid(dq)) return -1;
  if (dq->qtd == MAXN) return 1;
  else return 0;
}

int empty_deque(Deque* dq) {
  if (is_valid(dq)) return -1;
  if (dq->qtd == 0) return 1;
  else return 0;
}

int push_beginning(Deque* dq, int value) {
  if (is_valid(dq) || full_deque(dq)) return 0;

  dq->begin--;
  if (dq->begin < 0)
    dq->inicio = MAXN - 1;

  dq->data[dq->begin] = value;
  dq->qtd++;
  return 1;
}

int pop_beginning(Deque* dq) {
  if (is_valid(dq) || empty_deque(dq)) return 0;

  dq->inicio = (dq->inicio + 1) % MAXN;
  dq->qtd--;
  return 1;
}

int push_end(Deque* dq, int value) {
  if (is_valid(dq) || full_deque(dq)) return 0;

  dq->data[dq->end] = value;
  dq->end = (dq->end + 1) % MAXN;
  dq->qtd++;
  return 1;
}

int pop_end(Deque* dq) {
  if (is_valid(dq) || empty_deque(dq)) return 0;

  dq->end--;
  if (dq->end < 0)
    dq->end = MAXN - 1;
  dq->qtd--;
  return 1;
}

int bottom_deque(Deque* dq, int *value) {
  if (is_valid(dq) || empty_deque(dq)) return 0;

  *value = dq->data[dq->begin];
  return 1;
}

int top_deque(Deque* dq, int *value) {
  if (is_valid(dq) || empty_deque(dq)) return 0;

  int pos = dq->end - 1;
  if (pos < 0) // Se estiver na posicao zero, tem que voltar para o MAXN
    pos = MAXN - 1;
  *value = dq->data[pos];
  return 1;
}


