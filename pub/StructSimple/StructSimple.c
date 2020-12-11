// gcc -o StructSimple StructSimple.c -g -Wall && ./StructSimple

#include <stdio.h>
#include <stdlib.h>

static char *prog;

static void error(char *s) {
  fprintf(stderr,"%s: %s\n",prog,s);
  exit(1);
}

struct Student {
  char *name;
  int age;
};

// formal parameter is a copy of actual parameter
static void prv(struct Student a) {
  printf("%s: %d\n",a.name,a.age);
}

// formal parameter references actual parameter
static void prp(struct Student *a) {
  printf("%s: %d\n",a->name,a->age);
}

int main(int argc, char *argv[]) {
  prog=argv[0];

  struct Student s1;
  s1.name="ann";
  s1.age=21;

  struct Student s2={"bob",22};

  struct Student *s=(struct Student *)malloc(sizeof(*s));
  if (!s)
    error("malloc() failed");
  s->name="cam";
  s->age=23;

  prv(s1);
  prv(s2);
  prv(*s);
  prp(&s1);
  prp(&s2);
  prp(s);

  free(s);
  return 0;
}
