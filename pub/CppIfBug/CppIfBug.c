#include <stdio.h>

int main() {
#if OS == Linux
  printf("Linux\n");
#elif OS == Windows
  printf("Windows\n");
#else
# error Unrecognized value for OS
#endif
  return 0;
}
