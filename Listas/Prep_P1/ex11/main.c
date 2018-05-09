#include <stdio.h>
#include "stack.h"

int main() {
  char linebuffer[4096];
  fgets(linebuffer, sizeof(linebuffer), stdin);
  printf("%s\n", linebuffer);
    

  return 0;
}
