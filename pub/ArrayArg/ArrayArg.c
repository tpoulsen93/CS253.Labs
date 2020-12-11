// gcc -o ArrayArg ArrayArg.c -g -Wall -Wno-sizeof-array-argument && ./ArrayArg

#include <stdio.h>

#define SIZE 10

extern void pr(int a[], int size) {
  for (int i=0; i<size; i++)
    printf("%d%c",a[i],(i+1<size ? ' ' : '\n'));
}

extern void inc(int a[], int size) {
  printf("sizeof(a)=%ld\n",sizeof(a));
  a[size/2]++;
}

int main() {
  int a[SIZE];
  for (int i=0; i<SIZE; i++)
    a[i]=i+i;
  printf("sizeof(a)=%ld\n",sizeof(a));
  pr(a,SIZE);
  inc(a,SIZE);
  pr(a,SIZE);
  return 0;
}
