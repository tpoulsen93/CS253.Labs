//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#include <stdlib.h>
#include <stdio.h>
#include "Category.h"

Categories hardCodedCats = {
    {0, "Lowercase Vowels", "aeiou"},
    {0, "Lowercase Consonants", "bcdfghjklmnpqrstvwxyz"},
    {0, "Letters", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"},
};

Categories cats = {{0}};

Category newCategory(char *name, char *chars)
{
    Category newCategory;
    newCategory.count = 0;
    newCategory.name = name;
    newCategory.chars = chars;
    return newCategory;
}

void CharCatCount2(char target, Category *kittens)    //I'm getting tired of calling everything cats when kittens are so much cuter
{
    for (int i = 0; kittens[i].name; i++)
        for (int j = 0; kittens[i].chars[j]; j++)
                if (target == kittens[i].chars[j])
                    kittens[i].count++;
}

char *CategoryToString(Category category)
{
    char *output;
    asprintf(&output, "%s : %d", category.name, category.count);
    return output;
}