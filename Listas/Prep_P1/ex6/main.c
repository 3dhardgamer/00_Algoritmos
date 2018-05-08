#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main() {
  stack* stk1 = stack_create();
  stack* stk2 = stack_create();
  FILE *infile = fopen("seq_n_naturais.txt", "r");
  int i;

  fscanf(infile, "%d", &i);
  while (i != -1) {
    stack_push(stk1, i);
    fscanf(infile, "%d", &i);
  }
  fclose(infile);

  while (stk2->count < 1000)
    stack_push(stk2, stack_pop(stk1));

  stack_delete(stk1);

  while (stk2->count > 0)
    printf("%d\n", stack_pop(stk2));

  stack_delete(stk2);


  return 0;
}

