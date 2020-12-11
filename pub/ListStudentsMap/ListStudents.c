#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Student.h"
#include "list.h"
#include "listext.h"
#include "error.h"

static void prtstr(char *s) {
  printf("%s\n",s);
}

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

  List tss=map(students,(Mapf)studentToString);
  List vps=map(students,(Mapf)freeStudent);
  freelist(students);
  freelist(vps);

  vps=map(tss,(Mapf)prtstr);
  freedata(tss);
  freelist(vps);
  
  return 0;
}
