#include <stdio.h>
#include <stdlib.h>

typedef struct T {
  int i;
  struct T *t;
} *T;

static void error(char *s) {
  fprintf(stderr,"%s\n",s);
  exit(1);
}

int main() {
  T t1,t2;
  if (!(t1=(T)malloc(sizeof(*t1))))
    error("out of memory");
  if (!(t2=(T)malloc(sizeof(*t2))))
    error("out of memory");
  t1->i=100;
  t1->t=t2;
  t2->i=200;
  t2->t=0;
  return 0;
}
