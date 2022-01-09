#include "alex.h"
#include "fun_stack.h"

#include <ctype.h>
#include <string.h>


static int  ln= 1;
static char ident[256];
static FILE *ci= NULL;
static int gc;

void    alex_init4file( FILE *in ) 
{
   ln= 1;
   ci= in;
}

int isKeyword(char* ident)
{
  if(strcmp(ident, "if")==0)
    return 0;
  else if(strcmp(ident, "while")==0)
    return 0;
  else if(strcmp(ident, "fgetc")==0)
    return 0;
  else if(strcmp(ident, "malloc")==0)
    return 0;
  else if(strcmp(ident, "strcpy")==0)
    return 0;
  else if(strcmp(ident, "sizeof")==0)
    return 0;
  else if(strcmp(ident, "strcmp")==0)
    return 0;
  else if(strcmp(ident, "strlen")==0)
    return 0;
  else if(strcmp(ident, "free")==0)
    return 0;
  else if(strcmp(ident, "fopen")==0)
    return 0;
  else if(strcmp(ident, "switch")==0)
    return 0;
  else if(strcmp(ident, "for")==0)
    return 0;
  else if(strcmp(ident, "int")==0)
    return 0;
  else if(strcmp(ident, "char")==0)
    return 0;
  else if(strcmp(ident, "double")==0)
    return 0;
  else if(strcmp(ident, "float")==0)
    return 0;
  else if(strcmp(ident, "printf")==0)
    return 0;
  else if(strcmp(ident, "else")==0)
    return 0;
  else if(strcmp(ident, "fprintf")==0)
    return 0;
  else if(strcmp(ident, "scanf")==0)
    return 0;
  else if(strcmp(ident, "exit")==0)
    return 0;
  else if(strcmp(ident, "void")==0)
    return 0;  
  else if(strcmp(ident, "static")==0)
    return 0;
  else if(strcmp(ident, "lexem_t")==0)
    return 0;
  else{
    return 1;
  }
}

lexem_t alex_nextLexem( void ) 
{
  int c;
  while( (c= fgetc(ci)) != EOF ) {
    //printf("%c", c);
    if( c==' ' )
                        continue;
                else if( c == '\n' )
                { 
                        //printf("TO JEST NOWA LINIA, %d\n ", ln);
                        ln++;
                        //printf("NowaLinia");
                }
                        
    else if( c == '(' ){
      //printf("to jest nawias\n");
                        return OPEPAR;
    }
    else if( c == ')' )
      return CLOPAR;
    else if( c == '{' ){
      
                        return OPEBRA;}
    else if( c == '}' )
                        return CLOBRA;
    else if( isalpha( c ) ) {
      int i= 1;
      ident[0] = c;
      while( isalnum( c= fgetc(ci) )|| c=='_' ){
       //printf("%c", c);
                                ident[i++] = c;
      }
                        ident[i] = '\0';
                        gc=c;
      return isKeyword(ident)==0 ? OTHER: IDENT;
                } else if( c == '"' ) {
      /* Uwaga: tu trzeba jeszcze poprawic obsluge nowej linii w trakcie napisu
         i \\ w napisie 
      */
      int cp = c;
                        while( (c= fgetc(ci)) != EOF && c != '"' && cp == '\\' ) {
                          //printf("%c", c);
                                cp = c;
      }
      return c==EOF ? EOFILE : OTHER; 
    } else if( c == '/' ) {
      /* moze byc komentarz */
                } if( isdigit( c ) || c == '.' ) {
      /* liczba */
                } else {
      return OTHER;
                }
        }       
  return EOFILE;
}

char *  alex_ident( void ) 
{
   return ident;
}


lexem_t alex_next_ident( void ) 
{
  int c =gc;
  while(c==' '|| c=='\n'){
    //printf("%c", c);
    if(c=='\n'){
      ln++;
      break;
    }
    c= fgetc(ci);
    continue;
  }
  if( c == '(' ){
    //printf("%c", c);
      //printf("to jest nawias\n");
                        return OPEPAR;
    }
    else if( c == ')' )
      return CLOPAR;
    else if( c == '{' ){
                        return OPEBRA;
                        }
    else if( c == '}' )
                        return CLOBRA;
   else {
    return OTHER;
   }
}

int     alex_getLN() 
{
        return ln;
}

