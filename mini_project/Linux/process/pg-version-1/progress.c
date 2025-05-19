#include "progress.h"
#include <string.h>
void progress()
{ 
  char s[100]={'\0'}; int count =0;const char* emo = "-\\|/";
  for(count=0;count<101;++count)
  {
    printf("[%-100s][%d%%][%c]\r",s,count,emo[count%3]);
    fflush(stdout);
    usleep(30000);
    s[count] = '@';
  }
  printf("\n");
}
