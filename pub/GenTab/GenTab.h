#ifndef GENTAB_H
#define GENTAB_H

typedef void *GenTab;
typedef void *GenTabKey;
typedef void *GenTabData;

extern GenTab gtNew(int (*cmp)(GenTabKey k1, GenTabKey k2));
extern GenTabData gtGet(GenTab tab, GenTabKey key);
extern void gtPut(GenTab tab, GenTabKey key, GenTabData data);

#endif
