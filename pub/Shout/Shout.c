// gcc -o Shout Shout.c -g -Wall && ./Shout

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *line=0;
  size_t n=0;
  while (1) {
    ssize_t len=getline(&line,&n,stdin);
    if (len<0)
      break;
    for (int i=0; i<len; i++)
      if (line[i]>='a' && line[i]<='z')
	line[i]-='a'-'A';
    printf("%s",line);
  }
  free(line);
  return 0;
}
