#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"
#define size 100

int top=-1;
char* fun_stack[size];
int par_level_stack[size];

int top_of_funstack ( void )
{
  if(top>-1){
    return par_level_stack[top];
  }
  else{
    //fprintf(stderr, "Stack underflow 1 - na stosie niczego nie ma!");
    return 903824;
  }
}

void put_on_fun_stack ( int par_level, char *funame )
{
  if(top<size){
    top++;
    fun_stack[top]=malloc(strlen(funame)*sizeof(char));
    par_level_stack[top]=par_level;
    strcpy(fun_stack[top], funame); 
  }else{
    fprintf(stderr, "Stack overflow - stos przepełniony!");
  }
}

char *get_from_fun_stack ( void )
{
  if(top>-1){
    top--;
    return fun_stack[top+1];
  }else{
    fprintf(stderr, "Stack underflow - na stosie niczego nie ma!");
    return NULL;
  }
}