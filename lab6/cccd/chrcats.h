#ifndef CHRCATS_H
#define CHRCATS_H

typedef struct ChrCats *ChrCats;

struct ChrCats {

  void *rep;

  void (*addcat)(ChrCats this, char *name, char *chrs);
  void (*add)(ChrCats this, char c);
  char *(*toString)(ChrCats this);
  void (*free)(ChrCats this);

};

extern ChrCats chrcats_new();

#endif
