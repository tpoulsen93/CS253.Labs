//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include <stdio.h>
#include <stdlib.h>
#include "Category.h"
#include "stringy.h"
#include "list.h"

static void rangeCount(Category this, char target, char first, char last);
static void foldedRangeCount(Category this, char target, char first, char last);

//allocate and initialize a new Category
Category newCategory(char* name, char* characters)
{
    Category this = (Category)malloc(sizeof(*this));
    this->count = 0;
    this->name = name;
    this->chars = characters;
    return this;
}

//count matching characters between input and category and update category.count accordingly
void CharCatCount3(Category this, char target)
{
    if (this->chars[0] != '^')         //no capitalization folding
    {    
        for (int j = 0; this->chars[j]; j++)
            if (this->chars[j] != '-') //no range identifier
            {
                if (target == this->chars[j])
                    this->count++;
            }
            else  //range identifier is detected:
                rangeCount(this, target, this->chars[j-1], this->chars[j+1]);  
    }
    else          //capitalization folding is detected:
    {
        for (int j = 1; this->chars[j]; j++)
        {
            if (this->chars[j] != '-') //no range identifier
            {
                if (this->chars[j] >= 'a' && this->chars[j] <= 'z')       //if value is lowercase, check against both cases
                {
                    if (target == this->chars[j] || target == this->chars[j]-('a'-'A'))
                        this->count++;
                }
                else if (this->chars[j] >= 'A' && this->chars[j] <= 'Z')  //if value is uppercase, check against both cases 
                {
                    if (target == this->chars[j] || target == this->chars[j]+('a'-'A'))
                        this->count++;
                }
                else    //if value is not a letter, ignore folding, check like normal
                    if (target == this->chars[j])
                        this->count++;
            }
            else    //range identifier detected:
                foldedRangeCount(this, target, this->chars[j-1], this->chars[j+1]);
        }
    }
}

//check and count for characters in a given range (first char in range must be less than last char in range)
void rangeCount(Category this, char target, char first, char last)
{
    if (first < last)
    {    
        if (target < last && target > first)
            this->count++;
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
void foldedRangeCount(Category this, char target, char first, char last)
{
    if (first < last)
    {
        if (target >= 'a' && target <= 'z')         //target is lowercase, check against both cases
        {
            char fold = target - ('a'-'A');
            if ((target > first && target < last) || (fold > first && fold < last))
                this->count++;
        }
        else if (target >= 'A' && target <= 'Z')    //target is uppercase, check against both cases
        {
            char fold = target + ('a'-'A');
            if ((target > first && target < last) || (fold > first && fold < last))
                this->count++;
        }
        else        //target is not a letter. ignore folding, check like normal
            if (target < first && target > last)
                this->count++;
    }
    else
    {
        fprintf(stderr, "Illegal range parameters: beginning of range [%d: \'%c\'] must be less than end of range [%d: \'%c\'].\n", (int)first, first, (int)last, last);
        fprintf(stderr, "No counting was done on the range. Program integrity compromised. Please restart program.\n");
        exit(1);
    } 
}

//print string representation of a single Category
char* catToString(Category this)
{
	char* str;
    asprintf(&str, "%s : %d", this->name, this->count);
    return str;
}
