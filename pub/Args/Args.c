// gcc -o Args Args.c -g -Wall && ./Args foo 123 3.14

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc!=4) {
    fprintf(stderr,"Usage: %s <string> <int> <float>\n",argv[0]);
    exit(1);
  }
  printf("argument %d: %s\n",0,argv[0]);
  printf("argument %d: %s\n",1,argv[1]);
  printf("argument %d: %d\n",2,atoi(argv[2])); // ascii-to-int
  printf("argument %d: %f\n",3,atof(argv[3])); // ascii-to-float
  return 0;
}
