#include <stdlib.h>
#include "DynamicDeque.h"


// No do encadeamento dentro do Deque
// Definicao do elemento (tipo)
struct element {
  struct element *prev;
  struct element *next;
  int data;
};

typedef struct element Elem;


// No descritor do DEQUE
struct deque {
  struct element *begin;
  struct element *end;
  int qtd;
};

Deque* create_deque() {
  Deque* dq = (Deque*) malloc(sizeof(Deque));
  if (dq != NULL) {
    dq->begin = NULL;
    dq->end = NULL;
    dq->qtd = 0;
  }
  return dq;
}



