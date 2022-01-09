#ifndef _STORE_H_IS_INCLUDED_
#define _STORE_H_IS_INCLUDED_

#include "fun_stack.h"

typedef struct f{
  char* type;
  char* fun_name;
  int  line;
  char* inpname;
} fun_finder;


void store_add_def(char *get_from_fun_stack(), int alex_getLN(), char* inpname);
void store_add_proto(char *get_from_fun_stack(), int alex_getLN(), char* inpname);
void store_add_call(char *get_from_fun_stack(), int alex_getLN(), char* inpname);
void write();

#endif