#include <stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *next;
};

typedef struct element Elem;

struct queue {
  int count;
  Elem *begin;
  Elem * end;
};

typedef struct queue Queue;

// Definition of QUEUE operations
Queue* create_queue();
void delete_queue(Queue* qe);
int queue_size(Queue* qe);
int empty_queue(Queue* qe);
void enqueue(Queue* qe, int value);
void dequeue(Queue* qe, int *value);
void front(Queue* qe, int *value);

// Definition of STACK operations
void create_stack();
void delete_stack();
void push(int value);
void pop(int *value);
void top(int *value);

int main() {

  return 1;
}



// QUEUE Operations...
Queue* create_queue() {
  Queue* qe = (Queue*) malloc(sizeof(Queue));
  if (qe != NULL) {
    qe->begin = NULL;
    qe->end = NULL;
    qe->count = 0;
  }
  return qe;
}

void delete_queue(Queue* qe) {
  if (qe != NULL) {
    Elem* no;
    while (qe->begin != NULL) {
      no = qe->begin;
      qe->begin = no->next;
      free(no);
    }
    free(qe);
  }
}

int queue_size(Queue* qe) {
  return qe->count;
}

int empty_queue(Queue* qe) {
  if (qe == NULL) return 1;
  if (qe->begin == NULL) return 1;

  return 0;
}

void enqueue(Queue* qe, int value) {
  if (qe == NULL) return;

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return;
  no->data = value;
  no->next = NULL;

  if (qe->begin == NULL)
    qe->begin = no;
  else
    qe->begin->next = no;

  qe->end = no;
  qe->count++;
  return;
}

void dequeue(Queue* qe, int *value) {
  if (qe == NULL || empty_queue(qe)) return;

  *value = qe->begin->data; // Ponteiro que leva o dado que foi removido da fila
  Elem* no = qe->begin;
  qe->begin = no->next;

  if (qe->begin == NULL)
    qe->end = NULL;

  free(no);
  qe->count--;
  return;
}

void front(Queue* qe, int *value) {
  if (qe == NULL || empty_queue(qe)) return;

  *value = qe->begin->data; // Pontreiro que leva o dado da frente da fila
  return;
}

// STACK Operations
void create_stack() {
  Queue* qe1 = create_queue();
  Queue* qe2 = create_queue();
  return;
}

void delete_stack() {
  delete_stack(qe1);
  detele_stack(qe2);
  return;
}

void push(int value) {
  enqueue(qe1, value);
  return;
}

void pop(int *value) {
  int *aux;
  while (qe1->count != 1) {
    dequeue(qe1, &aux);
    enqueue(qe2, aux);
  }
  front(qe1, value);
  while (qe2->being != NULL) {
    dequeue(qe2, &aux);
    enqueue(qe1, aux);
  }
}

void top(int *value) {
  int *aux;
  while (qe1->count != 1) {
    dequeue(qe1, &aux);
    enqueue(qe1, aux);
  }
  front(qe1, value);
  dequeue(qe1, &aux);
  enqueue(qe1, aux);
}






