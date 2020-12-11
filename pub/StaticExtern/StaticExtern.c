#include <stdio.h>

#include "f.h"

static double foo() {
  return 1.23;
}

int main() {
  printf("dozen: %d\n",dozen);
  printf("f1: %d\n",f1());
  printf("f1: %d\n",f1());
  printf("f2: %d\n",f2());
  printf("f2: %d\n",f2());
  printf("f3: %d\n",f3());
  printf("f3: %d\n",f3());
  printf("foo: %f\n",foo());
  return 0;
}
