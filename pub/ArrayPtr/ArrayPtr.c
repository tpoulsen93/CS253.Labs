// gcc -o ArrayPtr ArrayPtr.c -g -Wall && ./ArrayPtr

#include <stdio.h>

#define SIZE 10

extern void pr(int a[], int size) {
  for (int i=0; i<size; i++)
    printf("%d%c",a[i],(i+1<size ? ' ' : '\n'));
}

extern void pr1(int a[], int size) {
  int *beg=&a[0];
  int *end=&a[size];
  for (int *p=beg; p<end; p++)
    printf("%d%c",*p,(p+1<end ? ' ' : '\n'));
}

extern void pr2(int a[], int size) {
  int *beg=a;
  int *end=a+size;
  for (int *p=beg; p<end; p++)
    printf("%d%c",*p,(p+1<end ? ' ' : '\n'));
}

extern void pr3(int *a, int size) {
  for (int *p=a; p<a+size; p++)
    printf("%d%c",*p,(p+1<a+size ? ' ' : '\n'));
}

int main() {
  int a[SIZE];
  for (int i=0; i<SIZE; i++)
    a[i]=i+i;
  pr(a,SIZE);
  pr1(a,SIZE);
  pr2(a,SIZE);
  pr3(a,SIZE);
}
