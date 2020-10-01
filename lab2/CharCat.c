//Character Category Struct Module
//Author: Taylor Poulsen
//Date: Sepember 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include "CharCat.h"

ChrCats chrcats={
    {0, "Upper Vowels", "AEIOU"},
    {0, "Lower Vowels", "aeiou"},
    {0, "My First Name", "taylorTAYLOR"},
    {0, "My Last Name", "poulsenPOULSEN"},
    {0}};   //terminating 0

    //compare a char from line[i] to each char in a category and count matches
int charCount(char targetChar, ChrCat category)
{
    int z = 0;
    while (category.chars[z])
    {
        if (targetChar == category.chars[z])
            category.count++;
        z++;
    }
    return category.count;
}