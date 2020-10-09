//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#ifndef CATEGORY_H
#define CATEGORY_H
#define MAXCATS = 10;

typedef struct {
	int count;
	char *name;
	char *chars;
}Category;

typedef Category Categories[];

extern Categories hardCodedCats;
extern Categories cats;
extern Category newCategory(char *name, char *chars);
extern void CharCatCount2(char target, Category *kittens);
extern char *CategoryToString(Category category);

#endif