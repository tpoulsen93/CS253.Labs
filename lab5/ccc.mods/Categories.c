//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include <stdlib.h>
#include <stdio.h>
#include "Categories.h"
#include "Category.h"
#include "list.h"

ChrCats newList()
{
    List cats = 0;
    return cats;
}

//add new category to category list
ChrCats addCategory(ChrCats cats, char* name, char* characters)
{
    cats = cons(newCategory(name, characters), cats);
    return cats;
}

//loop through List cats counting how many matches there are in each category
void count(ChrCats cats, char target)
{
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        CharCatCount3(car(tmp), target);
}

//return string representation of all categories
char* catsToString(ChrCats cats)
{
    char* output = (char*)malloc(sizeof(*output));
    for (List list = cats; list; list = cdr(list))
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

//change this one
void freeCats(ChrCats cats)
{
    freedata(cats);
}