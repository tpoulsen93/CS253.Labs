#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chrcats.h"
#include "Category.h"
#include "list.h"
#include "error.h"

static void chrcats_addcat(ChrCats this, char *name, char *chrs) 
{
    this = cons(newCategory(name, chrs), this);
}
static void chrcats_add(ChrCats this, char c)
{
    for (List tmp = this; tmp; tmp = cdr(tmp))
        CharCatCount3(car(tmp), c);
}
static char *chrcats_toString(ChrCats this)
{
    char* output = (char*)malloc(sizeof(*output));
    for (List list = this; list; list = cdr(list))
    {
        //make necessary assignments
        Category tmp = car(list);
        char* catStr = catToString(tmp);
        char* oldOutput = output;

        //concatenate new string onto old string
        asprintf(&output, "%s\n%s", catStr, output);

        //free old strings
        free(catStr);
        free(oldOutput);
    }
    return output;  
}
static void chrcats_free(ChrCats this)
{
    freedata(this);
}

extern ChrCats chrcats_new()
{
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
