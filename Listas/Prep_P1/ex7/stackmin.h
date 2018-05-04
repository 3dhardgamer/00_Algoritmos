#ifndef _STACKMIN_H_
#define _STACKMIN_H_

typedef struct stackmin stackmin;

struct stackmin {
  stack *def;
  stack *aux;
};

stackmin* stackmin_create();
void stackmin_delete(stackmin* stkmin);
void stackmin_push(stackmin* stkmin, int value);
int stackmin_pop(stackmin* stkmin);
int stackmin_top(stackmin* stkmin);
int stackmin_min(stackmin* stkmin);

#endif
