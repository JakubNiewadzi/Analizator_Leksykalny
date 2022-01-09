#include <stdio.h>

#include "parser.h"
#include "store.h"


int main (int argc, char** argv)  
{
  for(int i =1; i<argc;i++)  {
    analizatorSkladni(argv[i]);
  }
  write();
  return 0;
}