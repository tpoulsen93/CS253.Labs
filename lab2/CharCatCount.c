//Character Category Counter
//Author: Taylor Poulsen
//Date: September 2020
//Class: CS253
//Professor: Jim Buffenbarger


//gcc -o CharCatCount CharCatCount.c -g -Wall
//press enter without any input to terminate program


#include <stdio.h>
#include <stdlib.h>

typedef struct {...} ChrCat;
typedef ChrCat ChrCats[...];
static ChrCats chrcats={..., {0}};

int charCount(char target, char *category)  //parameters will be char from stdin and category we are checking it against
{
    for (int c = 0; c < (sizeof(/*something*/) / sizeof(char)))
    {
        if (target == /*something*/)
            return 1;
    }
    return 0;
}

int main()
{
    char *line = 0;
    size_t n = 0;
    int cat1 = 0;
    int cat2 = 0;
    int cat3 = 0;

    while (1) 
    {
        ssize_t length = getline(&line, &n, stdin);

        //terminate program if no input is given
        if (length <= 1)
            break;

        //loop through characters checking for their types and counting them
        for (int i = 0; i < length; i++)
        {
            if (charCount(line[i], /*category 1*/) > 0)     //I'm thinking this it is going to look something like this
                cat1++;
            if (charCount(line[i], /*category 2*/) > 0)
                cat2++;
            if (charCount(line[i], /*category 3*/) > 0)
                cat3++;
        }
    }
}