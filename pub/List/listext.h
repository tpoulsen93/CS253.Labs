#ifndef LISTEXT_H
#define LISTEXT_H

#include "list.h"

typedef List (*Mapf)(List val);

extern List map(List list, Mapf f);

#endif
