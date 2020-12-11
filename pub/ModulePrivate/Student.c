#include <stdio.h>
#include <stdlib.h>

#include "Student.h"

typedef struct {
  char *name;
  int age;
  char *major;
} *StudentRep;

// This function belongs in its own module.
static void error(char *s) {
  fprintf(stderr,"error: %s\n",s);
  exit(1);
}

static StudentRep newStudentRep() {
  StudentRep r=(StudentRep)malloc(sizeof(*r));
  if (!r)
    error("malloc() failed");
  return r;
}

extern Student newStudent(char *name, int age, char *major) {
  StudentRep r=newStudentRep();
  r->name=name;
  r->age=age;
  r->major=major;
  return (Student)r;
}

extern void freeStudent(Student s) {
  StudentRep r=(StudentRep)s;
  free(r->name);
  free(r->major);
  free(r);
}

extern char *studentToString(Student s) {
  StudentRep r=(StudentRep)s;
  char *ts;
  asprintf(&ts,"<%s %d %s>",r->name,r->age,r->major);
  return ts;
}


