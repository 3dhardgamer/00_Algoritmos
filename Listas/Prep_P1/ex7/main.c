#include <stdio.h>
#include "Stack.h"


// pushMin - modification of default push:
int pushMin(Stack* stk, Stack* stk_aux, int value) {
  int p1, p2;
  p1 = push(stk, value);
  if (stk_aux->top == NULL)
    p2 = push(stk_aux, value);
  else {
    if (value < stk_aux->top->data)
      p2 = push(stk_aux, value);
    else {
      int aux; // recebe valor do topo da pilha auxiliar
      int x = top(stk_aux, &aux);
      p2 = push(stk_aux, aux);
    }
  }
  if (p1 + p2 == 2) return 1;
  else return 0;
}

int popMin(Stack* stk, Stack* stk_aux, int *value) {
  int p1, p2;
  p1 = pop(stk, value);
  p2 = pop(stk_aux, value);

  if (p1 + p2 == 2) return 1;
  else return 0;
}

int topMin(Stack* stk, int *value) {
  return top(stk, value);
}

int minStack(Stack* stk_aux, int *value) {
  if (stk_aux == NULL) return 0;
  else return top(stk_aux, value);
}

int main () {
  Stack* stk = create_stack();
  Stack* stk_aux = create_stack();

  int p;
  int value, value_aux;
  p = pushMin(stk, stk_aux, 5);
  p = top(stk, &value);
  p = top(stk_aux, &value_aux);
  printf("STACK - %d :: STACK AUX - %d\n", value, value_aux);

  p = pushMin(stk, stk_aux, 3);
  p = top(stk, &value);
  p = top(stk_aux, &value_aux);
  printf("STACK - %d :: STACK AUX - %d\n", value, value_aux);

  p = pushMin(stk, stk_aux, 4);
  p = top(stk, &value);
  p = top(stk_aux, &value_aux);
  printf("STACK - %d :: STACK AUX - %d\n", value, value_aux);

  p = pushMin(stk, stk_aux, 6);
  p = top(stk, &value);
  p = top(stk_aux, &value_aux);
  printf("STACK - %d :: STACK AUX - %d\n", value, value_aux);

  p = pushMin(stk, stk_aux, 2);
  p = top(stk, &value);
  p = top(stk_aux, &value_aux);
  printf("STACK - %d :: STACK AUX - %d\n", value, value_aux);


  return 1;
}
