//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#include <stdlib.h>
#include <stdio.h>
#include "Category.h"
#include "error.h"
#include "stringy.h"


Categories cats = {{0}};
static void rangeCount(Category* kitten, char target, char first, char last);
static void foldedRangeCount(Category* kitten, char target, char first, char last);

Category newCategory(char* name, char* characters)
{
    Category newCategory;
    newCategory.count = 0;
    newCategory.name = name;
    newCategory.chars = characters;
    return newCategory;
}

void CharCatCount2(char target, Category* kittens)    //why call everything cats when kittens are so much cuter? :)
{
    for (int i = 0; kittens[i].name; i++)
    {
        if (kittens[i].chars[0] != '^')         //no capitalization folding
        {    
            for (int j = 0; kittens[i].chars[j]; j++)
                if (kittens[i].chars[j] != '-') //no range identifier
                {
                    if (target == kittens[i].chars[j])
                        kittens[i].count++;
                }
                else  //range identifier is detected:
                    rangeCount(&kittens[i], target, kittens[i].chars[j-1], kittens[i].chars[j+1]);  
        }
        else          //capitalization folding is detected:
        {
            for (int j = 1; kittens[i].chars[j]; j++)
            {
                if (kittens[i].chars[j] != '-') //no range identifier
                {
                    if (kittens[i].chars[j] >= 'a' && kittens[i].chars[j] <= 'z')       //if value is lowercase, check against both cases
                    {
                        if (target == kittens[i].chars[j] || target == kittens[i].chars[j]-('a'-'A'))
                            kittens[i].count++;
                    }
                    else if (kittens[i].chars[j] >= 'A' && kittens[i].chars[j] <= 'Z')  //if value is uppercase, check against both cases 
                    {
                        if (target == kittens[i].chars[j] || target == kittens[i].chars[j]+('a'-'A'))
                            kittens[i].count++;
                    }
                    else    //if value is not a letter, ignore folding, check like normal
                        if (target == kittens[i].chars[j])
                            kittens[i].count++;
                }
                else    //range identifier detected:
                    foldedRangeCount(&kittens[i], target, kittens[i].chars[j-1], kittens[i].chars[j+1]);
            }
        }
    }
}

//create a neatly printable representation for the category
char* CategoryToString(Category category)
{
    char* output;
    asprintf(&output, "%s : %d", category.name, category.count);
    return output;
}

//check and count for characters in a given range (first char in range must be less than last char in range)
void rangeCount(Category* kitten, char target, char first, char last)
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
void foldedRangeCount(Category* kitten, char target, char first, char last)
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