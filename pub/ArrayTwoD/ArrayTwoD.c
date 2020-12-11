// gcc -o ArrayTwoD ArrayTwoD.c -g -Wall -Wno-sizeof-array-argument && ./ArrayTwoD

#include <stdio.h>

#define ROWS 3
#define COLS 4

// parameter order is critical!
// outer dimension of array parameter is optional
extern void pr(int rows, int cols, int a[rows][cols]) {
  printf("a=%p\n",a);
  printf("sizeof(a)=%ld\n",sizeof(a));
  for (int row=0; row<rows; row++)
    for (int col=0; col<cols; col++)
      printf("%d%c",a[row][col],(col+1<cols ? ' ' : '\n'));
}  

int main() {
  int a[ROWS][COLS];
  printf("a=%p\n",a);
  printf("sizeof(a)=%ld\n",sizeof(a));
  for (int row=0; row<ROWS; row++)
    for (int col=0; col<COLS; col++)
      a[row][col]=row+col;
  pr(ROWS,COLS,a);
  return 0;
}
