//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

//returns the number of characters in a string (not including terminating 0)
int getStringSize(char* input)
{
    int size = 0;
    while (input[size])
        size++;
    return size;
}