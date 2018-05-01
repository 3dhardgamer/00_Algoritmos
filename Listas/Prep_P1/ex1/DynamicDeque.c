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
// Tem a informacao do inicio (begin), do fim (end) e da quantidade de elementos (qtd)
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

void delete_deque(Deque* dq) {
  if (dq != NULL) {
    Elem* no;
    while (dq->begin != NULL) {
      no = dq->begin;
      dq->begin = dq->begin->next;
      free(no);
    }
    free(dq);
  }
}

int deque_size(Deque* dq) {
  if (dq == NULL) return 0;
  return dq->qtd;
}

int empty_deque(Deque* dq) {
  if (dq == NULL) return -1;
  if (dq->begin == NULL) return 1;
  return 0;
}

int full_deque(Deque* dq) {
  return 0;
}

int top_deque(Deque* dq, int *value) {
  if (dq == NULL) return 0;
  if (dq->begin == NULL) return 0;

  *value = dq->begin->data;
  return 1;
}

int bottom_deque(Deque* dq, int *value) {
  if (dq == NULL) return 0;
  if (dq->end == NULL) return 0;

  *value = dq->end->data;
  return 1;
}

int push_beginning(Deque* dq, int value) {
  if (dq == NULL) return 0;
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return 0;

  no->data = value;
  no->next = dq->begin;
  no->prev = NULL;

  if (dq->begin == NULL)
    dq->end = no;
  else
    dq->begin->prev = no;
  dq->begin = no;
  dq->qtd++;
  return 1;
}

int push_end(Deque* dq, int value) {
  if (dq == NULL) return 0;
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return 0;

  no->data = value;
  no->next = NULL;

  if (dq->end == NULL) {
    no->prev = NULL;
    dq->begin = no;
  }
  else {
    no->prev = dq->end;
    dq->end->next = no;
  }
  dq->end = no;
  dq->qtd++;
  return 1;
}

int pop_beginning(Deque* dq) {
  if (dq == NULL) return 0;
  if (dq->begin == NULL) return 0;

  Elem* no = dq->begin;
  dq->begin = dq->begin->next;
  if (dq->begin == NULL)
    dq->end = NULL;
  else
    dq->begin->prev = NULL;

  free(no);
  dq->qtd--;
  return 1;
}

int pop_end(Deque* dq) {
  if (dq == NULL) return 0;
  if (dq->begin == NULL) return 0;

  Elem* no = dq->end;
  if (no == dq->begin) {
    dq->begin = NULL;
    dq->end = NULL;
  }
  else {
    no->prev->next = NULL;
    dq->end = no->prev;
  }

  free(no);
  dq->qtd--;
  return 1;
}


