#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

static void chkerr(char *s) {
  char *msg=dlerror();
  if (msg) {
    fprintf(stderr,"dl error: %s, %s\n",s,msg);
    exit(1);
  }
}

int main() {
  int plug=0;
  while (1) {
    char *lib;
    if (plug==0) { lib="libplugin0.so"; plug=1; }
    else         { lib="libplugin1.so"; plug=0; }
    void *handle=dlopen(lib,RTLD_LAZY);
    chkerr("open");
    void (*function)(void)=dlsym(handle,"plugin");
    chkerr("load");
    function();
    chkerr("execute");
    dlclose(handle);
    chkerr("close");
  }
  return 0;
}
