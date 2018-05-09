#include <stdio.h>
#include "stack.h"

int check_parentheses(char* linebuffer) {
  stack* stk_p = stack_create();
  stack* stk_t = stack_create();

  char p, t;
  int res;

  for (int i = 0; linebuffer[i]; i += 2) {
    p = linebuffer[i];
    t = linebuffer[i + 1];

    if (p == '(') {
      stack_push(stk_p, p);
      stack_push(stk_t, t);
    }
    else if (p == ')') {
      if (t == stack_peek(stk_t)) {
        stack_pop(stk_p);
        stack_pop(stk_t);
      }
      else {
        return -1;
      }
    }
  }
  res = stk_p->count;
  stack_delete(stk_p);
  stack_delete(stk_t);

  return res;
}

int main() {
  char linebuffer[4096];
  int res;
  fgets(linebuffer, sizeof(linebuffer), stdin);
  res = check_parentheses(linebuffer);
/*
  printf("\n\n");
  for (int i = 0; linebuffer[i]; i += 2)
    printf("%c%c\n", linebuffer[i], linebuffer[i + 1]);
*/
  if (res == 0) {
    printf("OK\n");
    return 0;
  }
  else {
    printf("incorreto\n");
    return 0;
  }
}
