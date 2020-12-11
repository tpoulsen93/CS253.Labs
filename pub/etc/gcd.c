// compile: gcc -o gcd gcd.c -g -Wall
// execute: ./gcd
// debug: gdb ./gcd       # line-oriented interface
// debug: gdb -tui ./gcd  # curses interface
// debug: ddd ./gcd       # fancy X11 frontend

#ifndef X
#define X 15
#endif

#ifndef Y
#define Y 25
#endif

#include <stdio.h>

int gcd(int a, int b) {
  while (a!=b) {
    if (a>b)
      a=a-b;
    else
      b=b-a;
  }
  return a;
}

int main() {
  printf("gcd(%d,%d)=%d\n",X,Y,gcd(X,Y));
  return 0;
}
