// gcc -o ArrayInit ArrayInit.c -g -Wall && ./ArrayInit

#include <stdio.h>

int main() {
  int a[]={0,2,4,6,8,1,3,5,7,9};
  printf("%ld\n",sizeof(a));
  int size=sizeof(a)/sizeof(int);
  for (int i=0; i<size; i++)
    printf("%d\n",a[i]);
  return 0;
}
