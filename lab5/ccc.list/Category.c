//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#include <stdlib.h>
#include <stdio.h>
#include "Category.h"
#include "error.h"
#include "stringy.h"
#include "list.h"

static List cats = 0;
static int currentIndex = 0;
static void rangeCount(Category kitten, char target, char first, char last);
static void foldedRangeCount(Category kitten, char target, char first, char last);
static void rangeError(char first, char last);


//add new category to category array
void addCategory(char* name, char* characters)
{
    Category newCategory = (Category)malloc(sizeof(*newCategory));
    newCategory->count = 0;
    newCategory->name = name;
    newCategory->chars = characters;

    cats = cons(newCategory, cats);
    currentIndex++;
}

//count matching characters between input and category and update category.count accordingly
void CharCatCount2(char target)
{
    for (List list = cats; list; list = cdr(list))
    {
        Category tmp = car(list);
        if (tmp->chars[0] != '^')         //no capitalization folding
        {    
            for (int j = 0; tmp->chars[j]; j++)
                if (tmp->chars[j] != '-') //no range identifier
                {
                    if (target == tmp->chars[j])
                        tmp->count++;
                }
                else  //range identifier is detected:
                    rangeCount(tmp, target, tmp->chars[j-1], tmp->chars[j+1]);  
        }
        else          //capitalization folding is detected:
        {
            for (int j = 1; tmp->chars[j]; j++)
            {
                if (tmp->chars[j] != '-') //no range identifier
                {
                    if (tmp->chars[j] >= 'a' && tmp->chars[j] <= 'z')       //if value is lowercase, check against both cases
                    {
                        if (target == tmp->chars[j] || target == tmp->chars[j]-('a'-'A'))
                            tmp->count++;
                    }
                    else if (tmp->chars[j] >= 'A' && tmp->chars[j] <= 'Z')  //if value is uppercase, check against both cases 
                    {
                        if (target == tmp->chars[j] || target == tmp->chars[j]+('a'-'A'))
                            tmp->count++;
                    }
                    else    //if value is not a letter, ignore folding, check like normal
                        if (target == tmp->chars[j])
                            tmp->count++;
                }
                else    //range identifier detected:
                    foldedRangeCount(tmp, target, tmp->chars[j-1], tmp->chars[j+1]);
            }
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
        rangeError(first, last);
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
        rangeError(first, last);
}

//return string representation of all categories
char* catToString()
{
    char* output = (char*)malloc(sizeof(*output));
    char* terminator = "";
    for (List list = cats; list; list = cdr(list))
    {
        if (!cdr(list))
            terminator = "\n";
        Category tmp = car(list);
        char* oldOutput = output;
        asprintf(&output, "%s\n%s : %d%s", output, tmp->name, tmp->count, terminator);
        free(oldOutput);
    }
    return output;
}

void freeCats()
{
    freedata(cats);
}

void rangeError(char first, char last)
{
    fprintf(stderr, "Illegal range parameters: beginning of range [%d: \'%c\'] must be less than end of range [%d: \'%c\'].\n", (int)first, first, (int)last, last);
    fprintf(stderr, "No counting was done on the range. Program integrity compromised. Please restart program.\n");
    exit(1);
}