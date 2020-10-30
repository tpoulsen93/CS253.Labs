//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#include <stdio.h>
#include <stdlib.h>
#include "Category.h"
#include "error.h"

static char* progName;

int main(int argc, char* argv[])
{
    if ((argc - 1) % 2)
        ERROR("Illegal parameter usage.\nUsage: [<CategoryName> <CategoryCharacters>...]");
    
    progName = argv[0];

    char* line = 0;
    size_t n = 0;

    int HCCats = 3;    //number of hardcoded categories
    addCategory("Lowercase Vowels", "aeiou");
    addCategory("Lowercase Consonants", "bcdfghjklmnpqrstvwxyz");
    addCategory("Letters", "^a-z");

    //arg[0] is the program name so we have to start at 1
    int currentArg = 1;
    int newCats = (argc-1)/2;
    int totalCats = newCats+HCCats;

    if (newCats)        //loop through provided input categories adding them to the category array
        for (int i = HCCats; i < totalCats; i++)
        {
            addCategory(argv[currentArg], argv[currentArg+1]);
            currentArg += 2;
        }

    while (1)
    {
        //get data from stdin
        ssize_t length = getline(&line, &n, stdin);

        //terminate program if blank input is given
        if (length <= 1)
            break;

        //loop through input characters checking for matches in categories
        for (int i = 0; i < length; i++)
            CharCatCount2(line[i]);
    }

    //loop through categories printing results
    for (int i = 0; i < getCatsSize(); i++)
    {
        char* result = catToString(getCat(i));
        printf("%s\n", result);
        free(result);
    }
    
    free(line);
    return 0;       //give os successful exit code
}