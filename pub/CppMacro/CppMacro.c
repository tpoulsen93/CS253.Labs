// gcc -o CppMacro CppMacro.c -g -Wall && ./CppMacro
// gcc -E -o CppMacro.i CppMacro.c

#include <stdio.h>

#define PRINTMAX(a,b) {          \
    if (a>b)                     \
        printf("left: %d\n",a);  \
    else                         \
        printf("right: %d\n",b); \
}

int main() {
  int i=1,j=2;
  PRINTMAX(i++,j++);
  PRINTMAX(i++,j++);
  return 0;
}
