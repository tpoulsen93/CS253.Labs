//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include <stdio.h>
#include "Category.h"
#include "stringy.h"

static void rangeCount(Category kitten, char target, char first, char last);
static void foldedRangeCount(Category kitten, char target, char first, char last);

Category newCategory(char* name, char* characters)
{
    Category newCategory = (Category)malloc(sizeof(*newCategory));
    newCategory->count = 0;
    newCategory->name = name;
    newCategory->chars = characters;
    return newCategory;
}

//count matching characters between input and category and update category.count accordingly
void CharCatCount3(Category cat, char target)
{
    if (cat->chars[0] != '^')         //no capitalization folding
    {    
        for (int j = 0; cat->chars[j]; j++)
            if (cat->chars[j] != '-') //no range identifier
            {
                if (target == cat->chars[j])
                    cat->count++;
            }
            else  //range identifier is detected:
                rangeCount(&cat, target, cat->chars[j-1], cat->chars[j+1]);  
    }
    else          //capitalization folding is detected:
    {
        for (int j = 1; cat->chars[j]; j++)
        {
            if (cat->chars[j] != '-') //no range identifier
            {
                if (cat->chars[j] >= 'a' && cat->chars[j] <= 'z')       //if value is lowercase, check against both cases
                {
                    if (target == cat->chars[j] || target == cat->chars[j]-('a'-'A'))
                        cat->count++;
                }
                else if (cat->chars[j] >= 'A' && cat->chars[j] <= 'Z')  //if value is uppercase, check against both cases 
                {
                    if (target == cat->chars[j] || target == cat->chars[j]+('a'-'A'))
                        cat->count++;
                }
                else    //if value is not a letter, ignore folding, check like normal
                    if (target == cat->chars[j])
                        cat->count++;
            }
            else    //range identifier detected:
                foldedRangeCount(&cat, target, cat->chars[j-1], cat->chars[j+1]);
        }
    }
}

//check and count for characters in a given range (first char in range must be less than last char in range)
void rangeCount(Category kitten, char target, char first, char last)
{
    if (first < last)
    {    
        if (target < last && target > first)
            kitten->count++;
    }
    else
    {
        fprintf(stderr, "Illegal range parameters: beginning of range [%d: \'%c\'] must be less than end of range [%d: \'%c\'].\n", (int)first, first, (int)last, last);
        fprintf(stderr, "No counting was done on the range. Program integrity compromised. Please restart program.\n");
        exit(1);
    }
}

//check and count for characters in a given range with capitalization folding
//first char in range must be less than last char in range  -  FOLDING ONLY WORKS FOR LETTERS
void foldedRangeCount(Category kitten, char target, char first, char last)
{
    if (first < last)
    {
        if (target >= 'a' && target <= 'z')         //target is lowercase, check against both cases
        {
            char fold = target - ('a'-'A');
            if ((target > first && target < last) || (fold > first && fold < last))
                kitten->count++;
        }
        else if (target >= 'A' && target <= 'Z')    //target is uppercase, check against both cases
        {
            char fold = target + ('a'-'A');
            if ((target > first && target < last) || (fold > first && fold < last))
                kitten->count++;
        }
        else        //target is not a letter. ignore folding, check like normal
            if (target < first && target > last)
                kitten->count++;
    }
    else
    {
        fprintf(stderr, "Illegal range parameters: beginning of range [%d: \'%c\'] must be less than end of range [%d: \'%c\'].\n", (int)first, first, (int)last, last);
        fprintf(stderr, "No counting was done on the range. Program integrity compromised. Please restart program.\n");
        exit(1);
    } 
}


char* catToString(Category cat)
{
    char* str;
    asprintf(&str, "%s : %d", cat->name, cat->count);
    return str;
}