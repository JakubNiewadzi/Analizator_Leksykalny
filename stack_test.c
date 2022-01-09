#include <stdio.h>
#include <stdlib.h>
#include "fun_stack.h"

int main(int argc, char** argv) {
  
  FILE *in = argc>1 ? fopen(argv[1], "r") : stdin;
  int x=1;
  
  printf("co chcesz zrobic(1 - dodanie na stos, 2 - pokazanie bilansu nawiasów, 3 - zdjęcie ze stosu i zwrócenie nazwy funkcji)\n");

  while(fscanf(in, "%d ", &x)==1)
  {
    
    if(x==1){
      char* napis=malloc(50*sizeof(char));
      fscanf(in, "%s", napis);
      put_on_fun_stack(x, napis);
      free(napis);
    }else if(x==2){      
      printf("%d\n", top_of_funstack());
    }else if(x==3){
      printf("%s\n", get_from_fun_stack());
    }else{
      printf("Podano niewłaściwy argument wejścia");
      break;
    }
   }
   /*put_on_fun_stack(5, "dodaj");
   put_on_fun_stack(5, "na");
   put_on_fun_stack(5, "stos");*/

  return 0;
  }

