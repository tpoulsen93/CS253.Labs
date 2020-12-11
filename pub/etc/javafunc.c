// gcc -o javafunc -Wall javafunc.c && ./javafunc

// public static int max(int x, int y) {
//   return x>y ? x : y;
// }

#include <stdio.h>

extern int max(int x, int y);	// C function declaration

extern int max(int x, int y) {	// C function definition
  return x>y ? x : y;
}

int main() {
  printf("%d\n",max(1,2));
  return 0;
}

