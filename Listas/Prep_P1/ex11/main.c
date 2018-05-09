#include <stdio.h>
#include "stack.h"

int main() {
  char linebuffer[4096];
//  char exp[] = "(p(p)p(p)p(p(p)p)p)p";
//  char exp[] = "(1(2)1)2";
//  char exp[] = "(1(2)2)1";
  while (fgets(linebuffer, sizeof(linebuffer), stdin))
    printf("%s\n", linebuffer);


  return 0;
}
