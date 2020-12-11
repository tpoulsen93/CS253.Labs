// gcc -o CppAlloc CppAlloc.c -g -Wall && ./CppAlloc
// gcc -E -o CppAlloc.i CppAlloc.c

#include <stdio.h>
#include <stdlib.h>

#define ALLOC(t,v)	            \
  t v=(t)malloc(sizeof(*v));        \
  if (!v) printf("malloc() failed")

typedef struct {
  int i;
  double d;
} *Foo;

typedef struct {
  char c;
  float f;
} *Bar;

int main() {
  ALLOC(Foo,foo);
  ALLOC(Bar,bar);
  return 0;
}
