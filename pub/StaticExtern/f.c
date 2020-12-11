#include "f.h"

const int dozen=12;

static int v=1;

static int foo() {
  return 123;
}

extern int f1() {
  static int v=100;
  return v++;
}

extern int f2() {
  static int v=200;
  return v++;
}

extern int f3() {
  foo();
  return v++;
}
