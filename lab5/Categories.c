//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include "Categories.h"
#include "Category.h"
#include "List/list.h"

static List cats = 0;
static int catCount = 0;

//add new category to category array
void addCategory(char* name, char* characters)
{
    Category newCat = newCategory(name, characters);
    cats = cons(newCat, cats);
    catCount++;
}

//return string representation of all categories
char* catsToString()
{
    char* output;
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        asprintf(&output, "%s\n%s", catToString(tmp), output);
    return output;
}

//change this one
void freeCats()
{
    free(cats);
}