#include <stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *prev;
};

typedef struct element Elem;

struct stack {
  int count;
  struct element *topo;
};

typedef struct stack Stack;

// Definition of STACK operations
Stack* create_stack();
void delete_stack();
int stack_size();
int empty_stack(Stack* stk);
void push(Stack* stk, int value);
void pop(Stack* stk, int *value);
void top(Stack* stk, int *value);

// Definition of QUEUE operations
void create_queue();
void delete_queue();
void enqueue(int value);
void dequeue(int *value);
void front(int *value);

// main flow
int main () {

  return 1;
}


// STACK Operations...
Stack* create_stack() {
  Stack* stk = (Stack*) malloc(sizeof(Stack));
  if (stk != NULL) {
    stk->topo = NULL;
    stk->count = 0;
  }
  return stk;
}

void delete_stack(Stack* stk) {
  if (stk != NULL) {
    Elem* no;
    while (stk->topo != NULL) {
      no = stk->topo;
      stk->topo = no->prev;
      free(no);
    }
    free(stk);
  }
}

int stack_size(Stack* stk) {
  return stk->count;
}

int empty_stack(Stack* stk) {
  if (stk == NULL) return -1;
  if (stk->topo == NULL) return 1;

  return 0;
}

void push(Stack* stk, int value) {
  if (stk == NULL) return;

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return;
  no->data = value;
  no->prev = stk->topo;
  stk->topo = no;
  return;
}

void pop(Stack* stk, int *value) {
  if (stk == NULL || empty_stack(stk)) return;

  *value = stk->topo->data;
  Elem* no = stk->topo;
  stk->topo = no->prev;

  free(no);
  stk->count--;
  return;
}

void top(Stack* stk, int *value) {
  if (stk == NULL || empty_stack(stk)) return;
  *value = stk->topo->data;
  return;
}



// QUEUE Operations...
void create_queue() {
  Stack* stk1 = create_stack();
  Stack* stk2 = create_stack();
  return;
}

void delete_queue() {
  delete_stack(stk1);
  delete_stack(stk2);
  return;
}

void enqueue(int value) {
  push(stk1, value);
  return;
}

void dequeue(int *value) {
  int *aux;
  while (stk1->topo != NULL) {
    pop(stk1, &aux);
    push(stk2, aux);
  }
  pop(stk2, &aux);

  while (stk2->topo ! = NULL) {
    pop(stk2, &aux);
    push(stk1, aux);
  }
}

void front(int *value) {
  int *aux;
  while (stk1->topo != NULL) {
    pop(stk1, &aux);
    push(stk2, aux);
  }
  *value = aux;
  while (stk2->topo != NULL) {
    pop(stk2, &aux);
    push(stk1, aux);
  }
}


