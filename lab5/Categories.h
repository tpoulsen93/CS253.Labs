//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include "Category.h"

#ifndef CATEGORIES_H
#define CATEGORIES_H


typedef void* Categories;
extern void addCategory(char *name, char *chars);
extern void freeCats();
extern char* catsToString();


#endif