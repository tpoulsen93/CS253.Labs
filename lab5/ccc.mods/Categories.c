//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include <stdlib.h>
#include <stdio.h>
#include "Categories.h"
#include "Category.h"
#include "list.h"

static List cats = 0;

//add new category to category array
void addCategory(char* name, char* characters)
{
    cats = cons(newCategory(name, characters), cats);
}

//loop through List cats counting how many matches there are in each category
void count(char target)
{
    for (List tmp = cats; tmp; tmp = cdr(tmp))
        CharCatCount3(car(tmp), target);
}

//return string representation of all categories
char* catsToString()
{
    char* output = (char*)malloc(sizeof(*output));
    char* terminator = "";
    for (List list = cats; list; list = cdr(list))
    {
        if (!cdr(list))
            terminator = "\n";
        Category tmp = car(list);
        char* oldOutput = output;
        asprintf(&output, "%s\n%s : %d%s", output, tmp->name, tmp->count, terminator);
        free(oldOutput);
    }
    return output;  
}

//change this one
void freeCats()
{
    freedata(cats);
}