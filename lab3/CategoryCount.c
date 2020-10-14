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
        exit(1);

    progName = argv[0];

    char* line = 0;
    size_t n = 0;

    int HCCats = 3;    //number of hardcoded categories
    cats[0] = newCategory("Lowercase Vowels", "aeiou");
    cats[1] = newCategory("Lowercase Consonants", "bcdfghjklmnpqrstvwxyz");
    cats[2] = newCategory("Letters", "^a-z");

    //arg[0] is the program name so we have to start at 1
    int currentArg = 1;

    if((argc-1))
    {
        int newCats = (argc-1)/2;
        int totalCats = newCats+HCCats;

        //loop through input categories adding them to the category array
        for (int i = HCCats; i < totalCats; i++)
        {
            cats[i] = newCategory(argv[currentArg], argv[currentArg+1]);
            currentArg += 2;
        }
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
            CharCatCount2(line[i], cats);
    }

    //loop through categories printing results
    for (int i = 0; cats[i].name; i++)
    {
        char *result = CategoryToString(cats[i]);
        printf("%s\n", result);
        free(result);
    }

    free(line);
    return 0;
}