//Author: Taylor Poulsen
//Date: October 2020
//Class: CS253
//Professor: Jim Buffenbarger

#include <stdlib.h>
#include <stdio.h>
#include "error.h"

extern void errorDetected(char *message)
{
    fprintf(stderr, "Error detected:\n%s", message);
    exit(1);
}
