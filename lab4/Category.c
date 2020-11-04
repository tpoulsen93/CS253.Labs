//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#include <stdlib.h>
#include <stdio.h>
#include "Category.h"
#include "error.h"
#include "stringy.h"


static Categories cats = 0;
static int currentIndex = 0;
static void rangeCount(Category* kitten, char target, char first, char last);
static void foldedRangeCount(Category* kitten, char target, char first, char last);

//add new category to category array
void addCategory(char* name, char* characters)
{
    Category newCategory;
    newCategory.count = 0;
    newCategory.name = name;
    newCategory.chars = characters;

    if ((currentIndex & (currentIndex-1)) == 0)   //current index is a power of 2 meaning arraysize needs to be doubled
    {
        cats = (Categories)realloc(cats, sizeof(*cats)*2*currentIndex);
        cats[currentIndex] = newCategory;
        currentIndex++;
    }
    else        //array has an available index
    {
        cats[currentIndex] = newCategory;
        currentIndex++;
    }
}

//count matching characters between input and category and update category.count accordingly
void CharCatCount2(char target)
{
    for (int i = 0; cats[i].name; i++)
    {
        if (cats[i].chars[0] != '^')         //no capitalization folding
        {    
            for (int j = 0; cats[i].chars[j]; j++)
                if (cats[i].chars[j] != '-') //no range identifier
                {
                    if (target == cats[i].chars[j])
                        cats[i].count++;
                }
                else  //range identifier is detected:
                    rangeCount(&cats[i], target, cats[i].chars[j-1], cats[i].chars[j+1]);  
        }
        else          //capitalization folding is detected:
        {
            for (int j = 1; cats[i].chars[j]; j++)
            {
                if (cats[i].chars[j] != '-') //no range identifier
                {
                    if (cats[i].chars[j] >= 'a' && cats[i].chars[j] <= 'z')       //if value is lowercase, check against both cases
                    {
                        if (target == cats[i].chars[j] || target == cats[i].chars[j]-('a'-'A'))
                            cats[i].count++;
                    }
                    else if (cats[i].chars[j] >= 'A' && cats[i].chars[j] <= 'Z')  //if value is uppercase, check against both cases 
                    {
                        if (target == cats[i].chars[j] || target == cats[i].chars[j]+('a'-'A'))
                            cats[i].count++;
                    }
                    else    //if value is not a letter, ignore folding, check like normal
                        if (target == cats[i].chars[j])
                            cats[i].count++;
                }
                else    //range identifier detected:
                    foldedRangeCount(&cats[i], target, cats[i].chars[j-1], cats[i].chars[j+1]);
            }
        }
    }
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

//get specific categories
Category getCat(int i)
{
    return cats[i];
}

//return string representation of all categories
char* catToString()
{
    char* output;
    for (int i = 0; i < currentIndex; i++)
    {
        if (i == 0)                     //first category
            asprintf(&output, "%s : %d", cats[i].name, cats[i].count);
        else if (i == currentIndex-1)   //last category
            asprintf(&output, "%s\n%s : %d\n", output, cats[i].name, cats[i].count);
        else                            //middle categories   
            asprintf(&output, "%s\n%s : %d", output, cats[i].name, cats[i].count);
    }
    return output;
}

void freeCats()
{
    free(cats);
}