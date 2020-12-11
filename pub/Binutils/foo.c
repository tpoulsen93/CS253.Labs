// gcc -o foo.s -S foo.c ; grep -E '\.(text|data|comm|section)' foo.s

// gcc -c foo.c ; size foo.o
// gcc -o foo foo.c ; size -A foo

// readelf -a foo.o
// objdump -h foo.o
// nm foo.o

#include <stdio.h>
#include <stdlib.h>

// static int bar[1];              // .comm / .bss
// static int bar[1]={1};          // .data / .data
// static const int bar[1]={1};    // .rodata / .text

int main() {
  // auto int bar[1];              // stack
  // auto int *bar=malloc(100);    // heap
  return 0;
}
