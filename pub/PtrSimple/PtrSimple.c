// gcc -o PtrSimple PtrSimple.c -g -Wall && ./PtrSimple

#include <stdio.h>

int main() {
  int i=11;
  int j=22;
  int *ip;
  int *jp;
  ip=&i;
  jp=&j;
  printf("%d %d\n",i,j);
  *ip=33;
  *jp=44;
  printf("%d %d\n",*ip,*jp);
  printf("%d %d\n",i,j);
  ip--;
  jp++;
  printf("%d %d\n",*ip,*jp);
  return 0;
}
