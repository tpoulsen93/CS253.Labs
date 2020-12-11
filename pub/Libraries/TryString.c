#include <stdio.h>

#include "String.h"

int main() {
  char *line=newString();
  line=catString(line,"hi");
  printf("%s\n",line);
  return 0;
}
