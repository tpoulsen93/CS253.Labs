#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "String.h"

static void error(char *s) {
  fprintf(stderr,"%s:%d %s\n",__FILE__,__LINE__,s);
  exit(1);
}

static char *alloc(int size) {
  char *t;
  if (!(t=(char *)malloc((size+1)*sizeof(char))))
    error("out of memory");
  return t;
}

extern char *newString() {
  char *s=alloc(0);
  strcpy(s,"");
  return s;
}

extern char *catString(char *s1, char *s2) {
  int l1=strlen(s1);
  int l2=strlen(s2);
  char *s=alloc(l1+l2);
  strcpy(s,s1);
  strcpy(s+l1,s2);
  free(s1);
  return s;
}
