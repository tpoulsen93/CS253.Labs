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
    for (int i = 0; i < sizeof(category.chars)/sizeof(char); i++)
    {
        if (targetChar == category.chars[i])
             category.count++;
    }
}

int main()
{
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
           for (int c = 0; c < sizeof(chrcats)/sizeof(ChrCat); c++)
           {
                charCount(line[i], chrcats[c]);
           }
        }

        for (int b = 0; b < sizeof(chrcats)/sizeof(ChrCat); b++)
        {
        printf("%s: %d\n",chrcats[b].name, chrcats[b].count);
        chrcats[b].count = 0;       //reset counters for next iteration
        }
    }
    free(line);
    return 0;
}