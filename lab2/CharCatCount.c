//Character Category Counter
//Author: Taylor Poulsen
//Date: September 2020
//Class: CS253
//Professor: Jim Buffenbarger


//gcc -o CharCatCount CharCatCount.c -g -Wall
//press enter without any input to terminate program


#include <stdio.h>
#include <stdlib.h>
#include "CharCat.h"

int main()
{
    int arrayIndex = 0;
    char *line = 0;
    size_t n = 0;

    while (1) 
    {
        //get data from stdin
        ssize_t length = getline(&line, &n, stdin);

        //terminate program if no input is given
        if (length <= 1)
            break;

        //loop through character categories checking for their types and counting them
        for (int i = 0; i < length; i++)
        {
           while (chrcats[arrayIndex].name)     //continue looping if category.name != 0
           {
                chrcats[arrayIndex].count = charCount(line[i], chrcats[arrayIndex]);
                arrayIndex++;
           }
           arrayIndex = 0;          //reset array loop counter for next iteration
        }
    }
    
    while (chrcats[arrayIndex].name != 0)
    {
        printf("%s: %d\n",chrcats[arrayIndex].name, chrcats[arrayIndex].count);
        arrayIndex++;
    }

    free(line);
    return 0;
}