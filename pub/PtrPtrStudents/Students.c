#include <stdio.h>
#include <stdlib.h>

#include "Students.h"

// This function belongs in its own module.
static void error(char *s) {
  fprintf(stderr,"error: %s\n",s);
  exit(1);
}

extern Students newStudents() {
  return 0;
}

extern Students studentsAdd(Students students, Student student) {
  Students p=(Students)malloc(sizeof(*p));
  if (!p)
    error("malloc() failed");
  p->student=student;
  p->students=students;
  return p;
}

extern Students studentsNext(Students students) {
  return students->students;
}

extern Student studentsCurr(Students students) {
  return students->student;
}

extern void freeStudents(Students students) {
  while (students) {
    Students p=students;
    freeStudent(studentsCurr(p));
    students=studentsNext(p);
    free(p);
  }
}
	       
