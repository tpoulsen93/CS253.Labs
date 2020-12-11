#include <stdio.h>
#include <stdlib.h>

#include "Student.h"

// This function belongs in its own module.
static void error(char *s) {
  fprintf(stderr,"error: %s\n",s);
  exit(1);
}

extern Student newStudent(char *name, int age, char *major) {
  Student s=(Student)malloc(sizeof(*s));
  if (!s)
    error("malloc() failed");
  s->name=name;
  s->age=age;
  s->major=major;
  return s;
}

extern void freeStudent(Student s) {
  free(s->name);
  free(s->major);
  free(s);
}

extern char *studentToString(Student s) {
  char *ts;
  asprintf(&ts,"<%s %d %s>",s->name,s->age,s->major);
  return ts;
}


