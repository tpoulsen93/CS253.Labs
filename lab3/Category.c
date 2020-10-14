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
static void rangeCount(Category* kittens, char target, char first, char last);

Category newCategory(char* name, char* characters)
{
    Category newCategory;
    newCategory.count = 0;
    newCategory.name = name;
    newCategory.chars = characters;
    return newCategory;
}

//named this one CharCatCount2 because I did it differently than on the previous project
void CharCatCount2(char target, Category* kittens)    //why call everything cats when kittens are so much cuter? :)
{
    for (int i = 0; kittens[i].name; i++)
        if (kittens[i].chars[0] != '^')         //check for capitalization folding
        {    
            for (int j = 0; kittens[i].chars[j]; j++)
                if (kittens[i].chars[j] != '-') //check for range identifier
                {
                    if (target == kittens[i].chars[j])
                        kittens[i].count++;
                }
                else  //if range identifier is detected:
                    rangeCount(&kittens[i], target, kittens[i].chars[j-1], kittens[i].chars[j+1]);
                
        }
        else          //if capitalization folding is detected:
        {
            for (int j = 1; kittens[i].chars[j]; j++)
            {
                if (kittens[i].chars[j] != '-')
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
                    else    //if value is not a classic letter, don't do folding. check like normal
                        if (target == kittens[i].chars[j])
                            kittens[i].count++;
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

void rangeCount(Category* kittens, char target, char first, char last)
{
    for (int i = first+1; i < last; i++)
        if (target == (char)i)
            kittens->count++;
}