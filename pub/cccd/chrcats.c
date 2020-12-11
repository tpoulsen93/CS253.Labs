#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chrcats.h"
#include "error.h"

static void chrcats_addcat(ChrCats this, char *name, char *chrs) {}
static void chrcats_add(ChrCats this, char c) {}
static char *chrcats_toString(ChrCats this) { return strdup("foo\n"); }
static void chrcats_free(ChrCats this) {}

extern ChrCats chrcats_new() {
  ChrCats this=(ChrCats)malloc(sizeof(*this));
  if (!this)
      ERROR("malloc() failed.");
  this->rep=0;
  this->addcat=  chrcats_addcat;
  this->add=     chrcats_add;
  this->toString=chrcats_toString;
  this->free=    chrcats_free;
  return (ChrCats)this;
}
