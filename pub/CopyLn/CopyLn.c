#include <stdio.h>
#include <stdlib.h>
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
  FILE *is=stdin;
  FILE *os=stdout;
  if (strcmp(inp,"-")!=0)
    if ((is=fopen(inp,"r"))==NULL)
      usage();
  if (strcmp(out,"-")!=0)
    if ((os=fopen(out,"w"))==NULL)
      usage();
  enum { STR_SIZE=10 };
  char s[STR_SIZE];
  while (fgets(s,STR_SIZE,is)!=NULL)
    fputs(s,os);
  return 0;
}
