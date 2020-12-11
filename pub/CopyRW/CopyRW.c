#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

static char *prog;

static void usage() {
  fprintf(stderr,"%s: <input> <output>\n",prog);
  exit(1);
}

int main(int argc, char *argv[]) {
  prog=argv[0];
  if (argc!=3)
    usage();
  char *inp=argv[1];
  char *out=argv[2];
  int ifd=fileno(stdin);
  int ofd=fileno(stdout);
  if (strcmp(inp,"-")!=0)
    if ((ifd=open(inp,O_RDONLY))<0)
      usage();
  if (strcmp(out,"-")!=0)
    if ((ofd=creat(out,S_IRUSR|S_IWUSR))<0)
      usage();
  enum { BUF_SIZE=100 };
  char buf[BUF_SIZE];
  int n;
  while ((n=read(ifd,buf,BUF_SIZE))>0)
    write(ofd,buf,n);
  return 0;
}
