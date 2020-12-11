#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chrcats.h"
#include "Category.h"
#include "list.h"
#include "error.h"

static void chrcats_addcat(ChrCats this, char *name, char *chrs) 
{
    this->rep = (ChrCats)cons((List)newCategory(name, chrs), this->rep);
}
static void chrcats_add(ChrCats this, char c)
{
    for (List list = this->rep; list; list = cdr(list))
        CharCatCount3(car(list), c);
}
static char *chrcats_toString(ChrCats this)
{
	//create a sufficiently big char* (hopefully)
    char* output = (char*)malloc(sizeof(char[50]));
    for (List list = this->rep; list; list = cdr(list))
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
    freedata((List)this->rep);
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
