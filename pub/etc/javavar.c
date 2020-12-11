// gcc -o javavar -Wall javavar.c && ./javavar

// class Int { int val; }
// public static void swap(Int x, Int y) {
//     int t=y.val;
//     y.val=x.val;
//     x.val=t;
// }

#include <stdio.h>

extern void swap(int *x, int *y) {
  int t=*y;			// local variable definition
  *y=*x;
  *x=t;
}

static int x=1;			// module-global variable definition
static int y=2;			// module-global variable definition

extern int z;			// global variable declaration

int main() {
  printf("%d %d\n",x,y);
  swap(&x,&y);
  printf("%d %d\n",x,y);
  printf("%d\n",z);
  return 0;
}

int z=3;			// global variable definition
