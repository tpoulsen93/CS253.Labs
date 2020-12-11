// gcc -o ArrayEnum ArrayEnum.c -g -Wall && ./ArrayEnum

#include <stdio.h>

enum { ROWS=3 };
enum { COLS=4 };

extern void pr(int a[ROWS][COLS], int rows, int cols) {
  for (int row=0; row<rows; row++)
    for (int col=0; col<cols; col++)
      printf("%2d%c",a[row][col],(col+1<cols ? ' ' : '\n'));
}  

int main() {
  int a[ROWS][COLS]={{1,2},{5,6,7},{9,10,11,12}};
  pr(a,ROWS,COLS);
  return 0;
}
