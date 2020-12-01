//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#ifndef CATEGORIES_H
#define CATEGORIES_H

typedef void* ChrCats;

extern ChrCats newList();
extern ChrCats addCategory(ChrCats cats, char* name, char* chars);
extern void count(ChrCats cats, char target);
extern char* catsToString(ChrCats cats);
extern void freeCats(ChrCats cats);

#endif