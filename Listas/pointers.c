#include <stdio.h>


void swap(int num1, int num2){
  int 
}

int main(int argc, char *argv[]) {
  int a;
  int b;
  int *p, *q;

  p = &a;
  q = &b;

  *p = 3;
  b = 5;

  fprintf(stdin, "BEF: a: %i b: %i\n", a, b);
  swap();
  fprintf(stdin, "AFT: a: %i b: %i\n", a, b);
}
