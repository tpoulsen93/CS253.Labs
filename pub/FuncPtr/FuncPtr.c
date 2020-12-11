#include <stdio.h>

static int g(char *s, double d) {
  printf("%s %f\n",s,d);
  return 1;
}

int main() {
  int (*f)(char *s, double d);
  f=g;
  int x=f("hi",3.14);
  printf("%d\n",x);
  return 0;
}
