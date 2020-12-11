#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>

#include "cmd_thread.h"
#include "cmd_single.h"
#include "error.h"

extern void cmd_thread(FPP* fpp) {
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
  sigset_t set;
  sigset_t old;
  sigfillset(&set);
  pthread_sigmask(SIG_BLOCK,&set,&old);
  cmd_single(fpp);
  pthread_sigmask(SIG_SETMASK,&old,0);
  pthread_attr_destroy(&attr);
}
