//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include "stdlib.h"
#include "stdio.h"
#include "Categories.h"
#include "Category.h"
#include "list.h"

static List cats = 0;

//add new category to category array
void addCategory(char* name, char* characters)
{
    cats = cons(newCategory(name, characters), cats);
}

void count(char target)
{
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        CharCatCount3(car(tmp), target);
}

//return string representation of all categories
char* catsToString()
{
    char* output;
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        asprintf(&output, "%s\n%s", catToString(car(tmp)), output);
    return output;
}

//change this one
void freeCats()
{
    freedata(cats);
    freelist(cats);
}