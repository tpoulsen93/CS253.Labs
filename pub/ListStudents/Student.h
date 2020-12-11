#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
  char *name;
  int age;
  char *major;
} *Student;

extern Student newStudent(char *name, int age, char *major);
extern void freeStudent(Student s);
extern char *studentToString(Student s);

#endif
