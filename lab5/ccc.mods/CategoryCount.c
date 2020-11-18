//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#include <stdio.h>
#include <stdlib.h>
#include "Categories.h"
#include "error.h"

static char* progName;

int main(int argc, char* argv[])
{
    if ((argc - 1) % 2)
        ERROR("Illegal parameter usage.\nUsage: [<CategoryName> <CategoryCharacters>...]");
    
    progName = argv[0];

    char* line = 0;
    size_t n = 0;

    addCategory("Lowercase Vowels", "aeiou");
    addCategory("Lowercase Consonants", "bcdfghjklmnpqrstvwxyz");
    addCategory("Letters", "^a-z");

    if (argc - 1)        //loop through provided input categories adding them to the category array
        for (int currentArg = 1; argv[currentArg]; currentArg += 2)
            addCategory(argv[currentArg], argv[currentArg+1]);

    while (1)
    {
        //get data from stdin
        ssize_t length = getline(&line, &n, stdin);

        //terminate program if blank input is given
        if (length <= 1)
            break;

        //loop through input characters checking for matches in categories
        for (int i = 0; i < length; i++)
        {
            count(line[i]);
        }
    }

    //print out results of category counting
    char* catCount = catsToString();
    printf("%s", catCount);

    //free everything allocated on the heap
    free(catCount);
    freeCats();
    free(line);

    //give OS successful exit code
    return 0;       
}