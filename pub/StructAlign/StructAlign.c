// gcc -o StructAlign StructAlign.c -g -Wall && ./StructAlign

#include <stdio.h>

#include "ugly.h"

int main() {
  struct S1 {
    char a,b;
    char c,d;
    int i;
  } s1;
  struct S2 {
    char a,b;
    int i;
    char c,d;
  } s2;
  INFO(struct S1,s1);
  INFO(struct S2,s2);
  return 0;
}
