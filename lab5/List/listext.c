#include "listext.h"

extern List map(List list, Mapf f) {
  if (!list)
    return 0;
  List res=f(car(list));
  return cons(res,map(cdr(list),f));
}  
