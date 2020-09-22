//Vowel Counter
//Author: Taylor Poulsen
//Date: September 2020
//Class: CS253
//Professor: Jim Buffenbarger


// gcc -o Vcount Vcount.c -g -Wall
// press enter without any input to terminate program

#include <stdio.h>
#include <stdlib.h>

const char vowels[] = "aeiou";

//vcheck will compare a given char against the five possible vowels
int vcheck(char target)
{
	for (int c = 0; c < (sizeof(vowels) / sizeof(char)); c++)
	{
		if (target == vowels[c])
			return 1; 
	}
	return 0;
}


//setlower will check each char it is given and make sure it is lowercase
char setlower(char target)
{
	if (target <= 'Z' && target >= 'A')
		target += ('a'-'A');	
	return target;	
}

int main() 
{
	int vcount = 0;
	char *line = 0;
	size_t n = 0;

	while (1) {
		ssize_t length = getline(&line, &n, stdin);
		
		// terminate program if no input is given
		if (length <= 1)
 			break;

		//loop through characters changing them to lowercase and counting vowels
		for (int i = 0; i < length; i++)
		{
			line[i] = setlower(line[i]);
			if (vcheck(line[i]) > 0)
				vcount++;
		}
		printf("%d vowels found.\n", vcount);
		//reset vowel count for next iteration
		vcount = 0;
	}
	free(line);
	return 0;
}

