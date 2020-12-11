#include <stdio.h>
#include <stdlib.h>

#include "GenTab.h"

typedef struct List {
  GenTabKey key;
  GenTabData data;
  struct List *list;
} *List;

typedef struct {
  int (*cmp)(GenTabKey k1, GenTabKey k2);
  List list;
} *GenTabRep;

static void error(char *s) {
  fprintf(stderr,"%s:%d %s\n",__FILE__,__LINE__,s);
  exit(1);
}

extern GenTab gtNew(int (*cmp)(GenTabKey k1, GenTabKey k2)) {
  GenTabRep tab=(GenTabRep)malloc(sizeof(*tab));
  if (!tab)
    error("out of memory");
  tab->cmp=cmp;
  tab->list=0;
  return (GenTab)tab;
}

extern GenTabData gtGet(GenTab tab, GenTabKey key) {
  GenTabRep r=(GenTabRep)tab;
  List l=r->list;
  while (l) {
    if (r->cmp(key,l->key)==0)
      return l->data;
    l=l->list;
  }    
  return 0;
}

extern void gtPut(GenTab tab, GenTabKey key, GenTabData data) {
  List l=(List)malloc(sizeof(*l));
  if (!l)
    error("out of memory");
  l->key=key;
  l->data=data;
  GenTabRep r=(GenTabRep)tab;
  l->list=r->list;
  r->list=l;
}
