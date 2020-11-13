#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Student.h"
#include "list.h"
#include "error.h"

int main(int argc, char *argv[]) {
  // argc is one larger than the number of args
  const int argsPerStudent=3;
  if ((argc-1)%argsPerStudent)
    ERROR("arguments: [<name> <age> <major>] ...");

  int n=(argc-1)/argsPerStudent;

  List students=0;
  for (int i=0; i<n; i++)
    students=cons(newStudent(strdup(argv[i*argsPerStudent+1]),
			     atoi(  argv[i*argsPerStudent+2]),
			     strdup(argv[i*argsPerStudent+3])),
		  students);

  for (List p=students; p; p=cdr(p)) {
    char *ts=studentToString(car(p));
    printf("%s\n",ts);
    free(ts);
  }

  for (List p=students; p; p=cdr(p))
    freeStudent(car(p));
  freelist(students);
  
  return 0;
}
