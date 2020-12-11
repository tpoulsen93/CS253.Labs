// gcc -o arrptr2 arrptr2.c -g -Wall && ./arrptr2

#include <stdio.h>

void f(int *a1, int a2[]) {
  printf("%d\n",*a1);
  printf("%d\n",*a2);
  printf("%d\n",a1[0]);
  printf("%d\n",a2[0]);
  a1++;
  a2++;
  printf("%d\n",*a1);
  printf("%d\n",*a2);
  printf("%d\n",a1[0]);
  printf("%d\n",a2[0]);
  a1--;
  a2--;
  printf("%d\n",*(a1+1));
  printf("%d\n",*(a2+1));
  printf("%d\n",a1[1]);
  printf("%d\n",a2[1]);
  printf("%d\n",1[a1]);		// huh?
  printf("%d\n",1[a2]);		// huh?
}

int main() {
  int i[]={1234,4567};
  int *ip1=i;
  int *ip2=&i[0];
  f(ip1,ip2);
  return 0;
}
