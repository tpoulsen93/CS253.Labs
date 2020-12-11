// gcc -o PtrArrPtrs PtrArrPtrs.c -g -Wall && ./PtrArrPtrs 11 22 33

#include <stdio.h>
#include <stdlib.h>

static char *prog;

static void error(char *s) {
  fprintf(stderr,"%s: %s\n",prog,s);
  exit(1);
}

int main(int argc, char *argv[]) {
  prog=argv[0];

  // argc is one larger than the number of args
  // we'll use that to store the terminator
  int **nums=(int **)malloc(argc*sizeof(*nums));
  if (!nums)
    error("malloc() failed");
  nums[0]=0;			// terminator

  for (int i=0; i<argc-1; i++) {
    nums[i]=(int *)malloc(sizeof(*nums[i]));
    if (!nums[i])
      error("malloc() failed");
    *nums[i]=atoi(argv[i+1]);	// atoi = ascii-to-int
    nums[i+1]=0; 		// terminator
  }
  
  // array
  for (int i=0; i<argc-1; i++)
    printf("%d%c",*nums[i],(i+1<argc-1 ? ' ' : '\n'));

  // pointer/terminator
  for (int **p=nums; *p; p++)
    printf("%d%c",**p,(*(p+1) ? ' ' : '\n'));
  
  for (int **p=nums; *p; p++)
    free(*p);
  free(nums);

  return 0;
}
