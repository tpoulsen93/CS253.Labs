#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Student.h"
#include "Students.h"

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

  Students students=newStudents();
  for (int i=0; i<n; i++)
    students=studentsAdd(students,
			 newStudent(strdup(argv[i*argsPerStudent+1]),
				    atoi(  argv[i*argsPerStudent+2]),
				    strdup(argv[i*argsPerStudent+3])));

  for (Students p=students; p; p=studentsNext(p)) {
    char *ts=studentToString(studentsCurr(p));
    printf("%s\n",ts);
    free(ts);
  }

  freeStudents(students);
  return 0;
}
