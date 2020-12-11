// gcc -o Array2dInit Array2dInit.c -g -Wall -Wno-sizeof-array-argument && ./Array2dInit

#include <stdio.h>

#define ROWS 3
#define COLS 4

// parameter order is critical!
// outer dimension of array parameter is optional
extern void pr(int rows, int cols, int a[rows][cols]) {
  printf("sizeof(a)=%ld\n",sizeof(a));
  for (int row=0; row<rows; row++)
    for (int col=0; col<cols; col++)
      printf("%d%c",a[row][col],(col+1<cols ? ' ' : '\n'));
}  

int main() {
  int a[ROWS][COLS]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  int b[][COLS]=    {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  printf("sizeof(a)=%ld\n",sizeof(a));
  printf("sizeof(b)=%ld\n",sizeof(b));
  pr(ROWS,COLS,a);
  pr(ROWS,COLS,b);
  return 0;
}
