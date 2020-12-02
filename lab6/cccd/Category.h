//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#ifndef CATEGORY_H
#define CATEGORY_H

typedef struct {
	int count;
	char *name;
	char *chars;
} *Category;

extern Category newCategory(char* name, char* characters);
extern void CharCatCount3(Category cat, char target);
extern char* catToString(Category cat);

#endif