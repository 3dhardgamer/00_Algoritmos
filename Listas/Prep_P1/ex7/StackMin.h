#ifndef _STACKMIN_H_
#define _STACKMIN_H_

#include "stack.h"

typedef struct stackmin stackmin;

struct stackmin {
  stack *def;
  stack *aux;
};


#endif

