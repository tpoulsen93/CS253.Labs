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

    //Initialize new data structures
    ChrCats hCats = newList();  //hardcoded Cats
    ChrCats cCats = newList();  //commandline cats    

    //add hardcoded categories to their structure
    cCats = addCategory(cCats, "Lowercase Vowels", "aeiou");
    cCats = addCategory(cCats, "Lowercase Consonants", "bcdfghjklmnpqrstvwxyz");
    cCats = addCategory(cCats, "Letters", "^a-z");

    if (argc - 1)   //loop through provided input categories adding them to their structure
        for (int currentArg = 1; argv[currentArg]; currentArg += 2)
            cCats = addCategory(cCats, argv[currentArg], argv[currentArg+1]);

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
            count(hCats, line[i]);
            count(cCats, line[i]);
        }
    }

    //print out results of category counting
    char* hCatStr = catsToString(hCats);
    char* cCatStr = catsToString(cCats);
    printf("%s%s", hCatStr, cCatStr);

    //free everything allocated on the heap
    free(hCatStr);
    free(cCatStr);
    freeCats(hCats);
    freeCats(cCats);
    free(line);

    //give OS successful exit code
    return 0;       
}