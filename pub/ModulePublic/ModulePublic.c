#include <stdio.h>
#include <stdlib.h>

#include "Student.h"

static char *getstr() {
  char *line=0;
  size_t n=0;
  ssize_t len=getline(&line,&n,stdin);
  if (len>=0) {
    if (line[len-1]=='\n')
      line[len-1]=0;
    return line;
  }
  free(line);
  return 0;
}

int main() {
  enum { MAX=25 };
  Student class[MAX+1];
  for (int i=0; i<MAX; i++) {
    char *name=getstr();
    if (!name)
      break;
    char *age=getstr();
    char *major=getstr();
    class[i]=newStudent(name,atoi(age),major);
    free(age);
    class[i+1]=0;
  }
  for (int i=0; class[i]; i++) {
    char *line=studentToString(class[i]);
    printf("%s\n",line);
    free(line);
  }
  for (int i=0; class[i]; i++)
    freeStudent(class[i]);
  return 0;
}
