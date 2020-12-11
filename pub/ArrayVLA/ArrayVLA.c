// gcc -o ArrayVLA ArrayVLA.c -g -Wall -Wno-sizeof-array-argument && ./ArrayVLA

#include <stdio.h>

#define SIZE 10

extern void pr(int a[], int size) {
  for (int i=0; i<size; i++)
    printf("%d%c",a[i],(i+1<size ? ' ' : '\n'));
}

extern void inc(int a[], int size) {
  int b[size*2];
  for (int i=0; i<size*2; i++)
    b[i]=a[i/2];
  printf("sizeof(a)=%ld\n",sizeof(a));
  pr(a,size);
  printf("sizeof(b)=%ld\n",sizeof(b));
  pr(b,size*2);
}

int main() {
  int a[SIZE];
  for (int i=0; i<SIZE; i++)
    a[i]=i+i;
  inc(a,SIZE);
  return 0;
}
