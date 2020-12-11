#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Student.h"

static char *prog;

static void error(char *s) {
  fprintf(stderr,"%s: %s\n",prog,s);
  exit(1);
}

int main(int argc, char *argv[]) {
  prog=argv[0];

  // argc is one larger than the number of args
  const int argsPerStudent=3;
  if ((argc-1)%argsPerStudent)
    error("arguments: [<name> <age> <major>] ...");

  int n=(argc-1)/argsPerStudent;
  Student *students=(Student *)malloc((n+1)*sizeof(*students));
  if (!students)
    error("malloc() failed");

  for (int i=0; i<n; i++) {
    students[i]=newStudent(strdup(argv[i*argsPerStudent+1]),
			   atoi(  argv[i*argsPerStudent+2]),
			   strdup(argv[i*argsPerStudent+3]));
    students[i+1]=0; 		// terminator
  }
  
  for (Student *p=students; *p; p++) {
    char *ts=studentToString(*p);
    printf("%s\n",ts);
    free(ts);
  }
  
  for (Student *p=students; *p; p++)
    freeStudent(*p);
  free(students);

  return 0;
}
