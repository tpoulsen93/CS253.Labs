#define MEMINFO(VAR,MEM)                                      \
  printf("    %s.%s: offsets=%ld..%ld size=%ld\n",#VAR,#MEM,  \
         (void *)(&(VAR.MEM))-(void *)&VAR,                   \
         (void *)(&(VAR.MEM))-(void *)&VAR+sizeof(VAR.MEM)-1, \
         sizeof(VAR.MEM))

#define INFO(TAG,VAR)                                \
  printf("%s:\n",#TAG);                              \
  printf("    sizeof %-9s=%2ld\n",#TAG,sizeof(TAG)); \
  printf("    sizeof members  =%2ld\n",              \
         sizeof(VAR.a)+                              \
         sizeof(VAR.b)+                              \
         sizeof(VAR.c)+                              \
         sizeof(VAR.d)+                              \
         sizeof(VAR.i));                             \
  MEMINFO(VAR,a);                                    \
  MEMINFO(VAR,b);                                    \
  MEMINFO(VAR,c);                                    \
  MEMINFO(VAR,d);                                    \
  MEMINFO(VAR,i)
