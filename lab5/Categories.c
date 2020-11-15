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
extern void addCategory(char* name, char* characters)
{
    cats = cons(newCategory(name, characters), cats);
}

//loop through List cats counting how many matches there are in each category
extern void count(char target)
{
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        CharCatCount3(car(tmp), target);
}

//return string representation of all categories
extern char* catsToString()
{
    char* output;
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        if (output)
            asprintf(&output, "%s\n%s", catToString((Category)car(tmp)), output);
        else
            asprintf(&output, "%s\n", catToString((Category)car(tmp)));
        
    return output;
}

//change this one
extern void freeCats()
{
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        freeCat((Category)car(tmp));
    //freedata(cats);
    //freelist(cats);
}