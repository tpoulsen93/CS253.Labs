#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cmd_process.h"
#include "cmd_single.h"

extern void cmd_process(FPP* fpp) {
  if (fork())
    fpp_close(fpp);
  else
    cmd_single(fpp);
}
