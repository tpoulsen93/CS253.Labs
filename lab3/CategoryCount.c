//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger


#include <stdio.h>
#include <stdlib.h>
#include "Category.h"
#include "error.h"

static char *progName;

int main(int argc, char *argv[])
{
    progName = argv[0];

    char *line = 0;
    size_t n = 0;


    if ((argc - 1) % 2)
        errorDetected("Incorrect number of arguments.\tUsage: [<Name> <Characters>]\n");

    int hccSize = 0;

    //loop through hard coded categories adding them to the category array
    for (int i = 0; hardCodedCats[i].name; i++)
    {
        cats[i] = hardCodedCats[i];
        hccSize++;
    }

    //arg[0] is the program name so we have to start at 1
    int currentArg = 1;

    //loop through input categories adding them to the category array
    for (int i = hccSize; i < argc; i++)
    {
        cats[i] = newCategory(argv[currentArg], argv[currentArg+1]);
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