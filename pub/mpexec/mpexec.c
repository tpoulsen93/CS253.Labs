#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

static char *prog;

static void error(char *s) {
  fprintf(stderr,"%s: %s\n",prog,s);
  exit(1);
}

static void start(char *prog, char *fn, fd_set *fds) {
  int pd[2];			// pipe descriptors
  if (pipe(pd))
    error("pipe() failed");
  if (fork()) {			// parent
    FD_SET(dup(pd[0]),fds);	// save rd end of pipe for select()
    close(pd[0]);		// rd end of pipe
    close(pd[1]);		// wr end of pipe
  } else {			// child    
    close(fileno(stdin));	// input is fn
    dup2(pd[1],fileno(stdout));	// wr end of pipe
    close(pd[0]);		// rd end of pipe
    close(pd[1]);		// wr end of pipe
    execlp(prog,prog,fn,NULL);
    error("execlp() failed");
  }
}

static void cat(int fd) {
  FILE *f=fdopen(fd,"r");
  if (!f)
    error("fdopen() failed");
  char *line=0;
  size_t n=0;
  while (getline(&line,&n,f)>=0)
    printf("%s",line);
  free(line);
  fclose(f);
}

static void finish(int n, fd_set *fds) {
  // Nested function definitions are illegal in C++!
  void on_sigchld(int sig) {
    while (waitpid(0,0,WNOHANG)>0) n--;
  }
  signal(SIGCHLD,on_sigchld);
  while (n>0) {
    fd_set rdfds=*fds;
    int cnt=select(FD_SETSIZE,&rdfds,0,0,0);
    for (int fd=0; cnt>0 && fd<FD_SETSIZE; fd++)
      if (FD_ISSET(fd,&rdfds)) {
	FD_CLR(fd,fds);
	cat(fd);
	cnt--;
      }
  }
}

int main(int argc, char *argv[]) {
  prog=argv[0];
  if (argc<=1)
    error("arguments: <program> [ <file> ...]");
  int n=argc-2;			// number of children
  fd_set fds;
  FD_ZERO(&fds);
  for (int i=1; i<=n; i++)
    start(argv[1],argv[i+1],&fds);
  finish(n,&fds);
  return 0;
}
