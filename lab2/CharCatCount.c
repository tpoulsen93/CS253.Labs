//Character Category Counter
//Author: Taylor Poulsen
//Date: September 2020
//Class: CS253
//Professor: Jim Buffenbarger


//gcc -o CharCatCount CharCatCount.c -g -Wall
//press enter without any input to terminate program


#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int count;          //number of matches in category
    char *name;         //name of category
    char *chars;        //characters in category
} ChrCat;

typedef ChrCat ChrCats[];
static ChrCats chrcats={
    {0, "Upper Vowels", "AEIOU"},
    {0, "Lower Vowels", "aeiou"},
    {0, "My First Name", "taylorTAYLOR"},
    {0, "My Last Name", "poulsenPOULSEN"},
    {0}};   //terminating 0

void charCount(char targetChar, ChrCat category)
{
/*    int categorySize = sizeof(category.chars) / sizeof(char);
    for (int z = 0; z < categorySize; z++)
    {
        if (targetChar == category.chars[z])
             category.count++;
    }
*/
    int z = 0;
    while (category.chars[z])
    {
        if (targetChar == category.chars[z])
            category.count++;
        z++;
    }
}

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
                charCount(line[i], chrcats[arrayIndex]);
                arrayIndex++;
           }
           arrayIndex = 0;
        }

        for (int b = 0; b < sizeof(chrcats)/sizeof(ChrCat)-1; b++)
        {
        printf("%s: %d\n",chrcats[b].name, chrcats[b].count);
        chrcats[b].count = 0;       //reset counters for next iteration
        arrayIndex = 0;             //reset array loop counter for next iteration
        }
    }
    free(line);
    return 0;
}