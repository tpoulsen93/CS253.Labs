// gcc -o Enum Enum.c -g -Wall && ./Enum

#include <stdio.h>

enum Major
  {
   ART, BIOL, CS, ENGL,
   ENGR, GEOL, MATH, PHYS,
  };
	    
struct Student {
  char *name;
  int age;
  enum Major major;
};

static void pr(struct Student *a) {
  printf("%s: %d ",a->name,a->age);
  switch (a->major) {
    case ART: case ENGL:
      printf("liberal arts\n"); break;
    case BIOL: case GEOL: case PHYS:
      printf("science\n"); break;
    default:
      printf("computing, engineering, math, etc.\n"); break;
  }
}

int main() {
  struct Student s1={"ann",21,CS};
  struct Student s2={"bob",22,ART};
  pr(&s1);
  pr(&s2);
  return 0;
}
