#include <stdio.h>
#include <string.h>

#include "cmd_single.h"
#include "chrcats.h"
#include "list.h"
#include "error.h"

/***************************************************************************
 * This function zeroes the newline at the end of a string, if             *
 * it exists.                                                              *
 ***************************************************************************/
static int rmnl(char *s, int l) {
  if (l>0 && s[l-1]=='\n')
    s[--l]=0;
  return l;
}

/***************************************************************************
 * This function sends the toString representation of a category set       *
 * to the client.                                                          *
 ***************************************************************************/
static void print(FPP* fpp, ChrCats ccs) {
  char *ts=ccs->toString(ccs);
  fprintf(fpp->w,"%s",ts);
  fflush(fpp->w);
  free(ts);
}

/***************************************************************************
 * This function adds a category to a set of categories,                   *
 * according to a command like:                                            *
 *                                                                         *
 *     add vowel ^aeiou                                                    *
 *                                                                         *
 * Arguments:                                                              *
 *     - fpp: file-pointer pair (unused)                                   *
 *     - s: "add" command (e.g., above)                                    *
 *     - ccs: categories to add to                                         *
 *     - strings: ptrs to free, later                                      *
 ***************************************************************************/
static int cmd_add(FPP *fpp, char *s, ChrCats ccs, List *strings) {
  char *name;
  char *chrs;
  sscanf(s,"%*s %ms %m[^\n]\n",&name,&chrs);
  ccs->addcat(ccs,name,chrs);
  *strings=cons(name,cons(chrs,*strings));
  return 0;
}

/***************************************************************************
 * This function adds the characters in lines of text to a                 *
 * category set, beginning with a command like:                            *
 *                                                                         *
 *     txt .                                                               *
 *                                                                         *
 * followed by lines composing the text. The rest of the "txt"             *
 * line, after "txt" and whitespace, is a sentinel. The next               *
 * line equal to the sentinel indicates the end of the text.               *
 *                                                                         *
 * After the end of the text has been reached, a toString                  *
 * representation of the category set is sent to the client.               *
 *                                                                         *
 * Arguments:                                                              *
 *     - fpp: file-pointer pair for reading lines                          *
 *     - s: "txt" command (e.g., above)                                    *
 *     - ccs: categories to add to                                         *
 *     - strings: ptrs to free, later (unused)                             *
 ***************************************************************************/
static int cmd_txt(FPP *fpp, char *s, ChrCats ccs, List *strings) {
  char *eof;
  sscanf(s,"%*s %m[^\n]\n",&eof);
  char *txt=0;
  size_t n=0;
  while (1) {
    ssize_t len=getline(&txt,&n,fpp->r);
    len=rmnl(txt,len);
    if (len<0 || !strcmp(txt,eof))
      break;
    for (char *c=txt; *c; c++)
      ccs->add(ccs,*c);
  }
  free(txt);
  free(eof);
  print(fpp,ccs);
  return 1;
}

/***************************************************************************
 * This is the command table.                                              *
 ***************************************************************************/

typedef struct {
  char *name;
  int (*func)(FPP *fpp, char *s, ChrCats ccs, List *strings);
} Cmd;

static Cmd cmds[]=
  {
   {"add",cmd_add},
   {"txt",cmd_txt},
   {0,0}
  };

/***************************************************************************
 * This function services a client. Starting with an empty                 *
 * category set, it reads and performs a sequence of category              *
 * commands from the client.                                               *
 *                                                                         *
 * Arguments:                                                              *
 *     - fpp: file-pointer pair                                            *
 ***************************************************************************/
extern void cmd_single(FPP* fpp) {
  List strings=0;
  ChrCats ccs=chrcats_new();
  int done=0;
  while (!done) {
    char *s=0;
    size_t n=0;
    ssize_t len=getline(&s,&n,fpp->r);
    if (len>=0) {
      char *cmd;
      sscanf(s,"%ms",&cmd);
      done=1;
      for (Cmd *c=cmds; c->name; c++)
	if (!strcmp(cmd,c->name))
	  done=c->func(fpp,s,ccs,&strings);
      free(cmd);
      free(s);
    }
  }
  ccs->free(ccs);
  freedata(strings);
  fpp_close(fpp);
}
