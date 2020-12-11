#ifndef STUDENTS_H
#define STUDENTS_H

#include "Student.h"

typedef struct Students {
  Student student;
  struct Students *students;
} *Students;

extern Students newStudents();
extern Students studentsAdd(Students students, Student student);
extern Students studentsNext(Students students);
extern Student studentsCurr(Students students);
extern void freeStudents(Students students);

#endif
