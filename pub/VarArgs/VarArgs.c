// gcc -o VarArgs VarArgs.c -g -Wall && ./VarArgs

#include <stdio.h>
#include <stdarg.h>

static void strlist(int a, int b, ...) {
  printf("%d %d\n",a,b);
  va_list ap;
  va_start(ap,b);
  while (1) {
    char *s=va_arg(ap,char *);
    if (!s) break;
    printf("%s\n",s);
  }
  va_end(ap);
}

int main() {
  strlist(11,22,"string1","string2","string3",0);
  strlist(33,44,"STRING1","STRING2",0);
  return 0;
}
