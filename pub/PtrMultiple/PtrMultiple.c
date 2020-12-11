// gcc -o PtrMultiple PtrMultiple.c -g -Wall && ./PtrMultiple

#include <stdio.h>

int main() {
  int i=11;
  int *ip;
  int **ipp;
  ip=&i;
  ipp=&ip;
  printf("%d\n",**ipp);
  return 0;
}
