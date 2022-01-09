#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"
#include "store.h"

fun_finder arr[100];
int current=0;

void store_add_def(char *get_from_fun_stack(), int alex_getLN(), char* inpname) {
  arr[current].type=malloc(10*sizeof(char));
  arr[current].fun_name=malloc(100*sizeof(char));
  arr[current].inpname=malloc(100*sizeof(char));
  arr[current].type="definicja";
  strcpy(arr[current].fun_name, get_from_fun_stack());
  strcpy(arr[current].inpname, inpname);
  arr[current].line=alex_getLN();
  current++;
}
void store_add_proto(char *get_from_fun_stack(), int alex_getLN(), char* inpname) {
  arr[current].type=malloc(10*sizeof(char));
  arr[current].fun_name=malloc(100*sizeof(char));
  arr[current].inpname=malloc(100*sizeof(char));
  arr[current].type="prototyp";
  strcpy(arr[current].fun_name, get_from_fun_stack());
  strcpy(arr[current].inpname, inpname);
  arr[current].line=alex_getLN();
  current++;
}
void store_add_call(char *get_from_fun_stack(), int alex_getLN(), char* inpname) {
  arr[current].type=malloc(10*sizeof(char));
  arr[current].fun_name=malloc(100*sizeof(char));
  arr[current].inpname=malloc(100*sizeof(char));
  arr[current].type="wywołanie";
  strcpy(arr[current].fun_name, get_from_fun_stack());
  strcpy(arr[current].inpname, inpname);
  arr[current].line=alex_getLN();
  current++;
}

void write() {
  char* funkcje[100];

  int a=0;
  for(int i =0;i<current;i++){
    int b=0;
    for(int j=0;j<a;j++){
      if(strcmp(arr[i].fun_name, funkcje[a-1])==0){
        break;
      }else{
        b++;
      }
    }
    if(a==b){
      funkcje[a]=malloc(strlen(arr[i].fun_name)*sizeof(char));
      strcpy(funkcje[a], arr[i].fun_name);
      a++;
    }
  }
  /*for(int i =0;i<a;i++){
    printf("%s\n", funkcje[i]);
  }*/

  for(int i=0;i<a;i++){
    printf("Funkcja %s\n", funkcje[i]);
    printf("\tprototyp:\n");
    for(int j=0;j<current;j++){
      if(strcmp(funkcje[i], arr[j].fun_name)==0 && strcmp("prototyp", arr[j].type)==0){
        printf("\t\tplik %s, linia %d\n", arr[j].inpname, arr[j].line);
      }
    }
    printf("\tdefinicja:\n");
    for(int j=0;j<current;j++){
      if(strcmp(funkcje[i], arr[j].fun_name)==0 && strcmp("definicja", arr[j].type)==0){
        printf("\t\tplik %s, linia %d\n", arr[j].inpname, arr[j].line);
      }
    }
    printf("\twywołanie:\n");
    for(int j=0;j<current;j++){
      if(strcmp(funkcje[i], arr[j].fun_name)==0 && strcmp("wywołanie", arr[j].type)==0){
        printf("\t\tplik %s, linia %d\n", arr[j].inpname, arr[j].line);
      }
    }
  }

  for(int i=0;i<current;i++){
    //free(arr[i].type);
    free(arr[i].inpname);
    free(arr[i].fun_name);
  }
  for(int i=0;i<a;i++){
    free(funkcje[i]);
  }

}