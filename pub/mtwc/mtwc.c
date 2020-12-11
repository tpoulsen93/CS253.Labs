#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static char *prog;

static void error(char *s) {
  fprintf(stderr,"%s: %s\n",prog,s);
  exit(1);
}

static int wc(char *line) {
  enum State { In, Out } state=Out; // inside/outside a word
  int words=0;
  for (char *p=line; *p ; p++)
    switch (*p) {
      case ' ': case '\n': case '\t':
	state=Out;
	break;
      default:
	if (state==Out) {
	  state=In;
	  words++;
	}
	break;
    }
  return words;
}

static int eof=0;
static pthread_mutex_t mutex;

// Procure and Vacate
#define P() pthread_mutex_lock(&mutex)
#define V() pthread_mutex_unlock(&mutex)

static int count() {
  int words=0;
  char *line=0;
  size_t n=0;
  while (!eof) {
    P();
    if (!eof && getline(&line,&n,stdin)>=0) {
      V();
      words+=wc(line);
    } else {
      eof=1;
      V();
    }
  }
  free(line);
  return words;
}

static void *thread_func(void *a) {
  pthread_exit((void *)(long)count());
}

static void start(int i, pthread_t threads[]) {
  // Nested function definitions don't work!
  if (pthread_create(&threads[i],0,thread_func,(void *)(long)i))
    error("pthread_create() failed");
}

static void finish(int n, pthread_t threads[]) {
  int words=0;
  for (int i=1; i<=n; i++) {
    long twords;
    if (pthread_join(threads[i],(void *)&twords))
      error("pthread_join() failed");
    words+=twords;
  }
  printf("%d\n",words);
}

int main(int argc, char *argv[]) {
  prog=argv[0];
  if (argc!=2)
    error("arguments: <threads>");
  int n=atoi(argv[1]);			// number of threads
  pthread_t threads[n];			// VLA
  pthread_mutex_init(&mutex,0);
  for (int i=1; i<=n; i++)
    start(i,threads);
  finish(n,threads);
  pthread_exit(0);
}
