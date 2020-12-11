#include <stdio.h>

#define Linux 1
#define Windows 2
#define Mac 3

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
