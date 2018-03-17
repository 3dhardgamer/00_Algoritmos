#include  <stdio.h>

int main(int argc, char *argv[]) {
  int a;
  int * p;

  a = 24;

  //p = a;
  //p = *a;
  //p = &a;
  *p = a;

  fprintf(stdout, "a: %i %p\n", a, &a);
  fprintf(stdout, "p: %i %p\n", *p, &p);

  return 0;
}
