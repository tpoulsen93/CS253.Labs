// gcc -o UnionSimple UnionSimple.c -g -Wall && ./UnionSimple

#include <stdio.h>

#include "ugly.h"

int main() {
  union U {
    char a,b;
    int i;
    char c,d;
  } u;
  INFO(union U,u);
  return 0;
}
