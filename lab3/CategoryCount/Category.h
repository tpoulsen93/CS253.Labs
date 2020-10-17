//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#ifndef MAXCATS
#define MAXCATS 10
#endif


#ifndef CATEGORY_H
#define CATEGORY_H

typedef struct {
	int count;
	char *name;
	char *chars;
}Category;

typedef Category Categories[MAXCATS];
extern Categories cats;
extern Category newCategory(char *name, char *chars);
extern void CharCatCount2(char target, Category *kittens);
extern char* CategoryToString(Category category);

#endif