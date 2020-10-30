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
} Category;

typedef Category* Categories;
extern void addCategory(char *name, char *chars);
extern void CharCatCount2(char target);
extern Category getCat(int i);
extern char* catToString(Category kitty);
extern int getCatsSize();

#endif