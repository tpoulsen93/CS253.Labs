// gcc -o PtrAlloc PtrAlloc.c -g -Wall && ./PtrAlloc

#include <stdio.h>
#include <stdlib.h>

static char *prog;		// prog is allocated statically

static void error(char *s) {
  fprintf(stderr,"%s: %s\n",prog,s);
  exit(1);
}

extern void pr(int *a, int size) { // a and size are on the stack
  for (int *p=a; p<a+size; p++)	   // p is on the stack
    printf("%d%c",*p,(p+1<a+size ? ' ' : '\n'));
}

int main(int argc, char *argv[]) {  // argv and its elements are on the stack
  prog=argv[0];			    // *prog is on the stack

  int *p=(int *)malloc(sizeof(*p)); // p is allocated on the stack
  if (!p)			    // *p is allocated in the heap
    error("malloc() failed");
  *p=123;
  printf("&p=%p p=%p *p=%d\n",&p,p,*p);
  free(p);

  int a[]={11,1,33};		    // a and its elements are on the stack
  int elms=sizeof(a)/sizeof(a[0]);
  pr(a,elms);

  int *b=(int *)malloc(sizeof(a));  // b is on the stack
  if (!b)			    // b's elements are in the heap
    error("malloc() failed");

  a[1]=2;			// arrays
  for (int i=0; i<elms; i++)
    b[i]=a[i];
  pr(b,elms);

  a[1]=3;			// pointers
  for (int *p=b,*q=a; p<b+elms; p++,q++)
    *p=*q;
  pr(p,elms);
    
  a[1]=4;			// party tricks
  for (int *p=b,*q=a; p<b+elms; *p++=*q++);
  pr(p,elms);

  free(b);
  return 0;
}
