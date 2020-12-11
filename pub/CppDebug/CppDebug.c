#include <stdio.h>

int main() {
  int i=1;
#if defined(DEBUG)
  printf("i: %d\n",i);
#endif
  return 0;
}
