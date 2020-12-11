// gcc -o ArraySimple ArraySimple.c -g -Wall && ./ArraySimple

#include <stdio.h>

// const int size=10; // makes it a VLA
// enum { size=10; }; // works too
#define SIZE 10

int main() {
  int a[SIZE];
  for (int i=0; i<SIZE; i++)
    a[i]=i+i;
  for (int i=0; i<SIZE; i++)
    printf("%d\n",a[i]);
  return 0;
}
