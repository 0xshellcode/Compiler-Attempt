/*-----------------------------------------------*/
/* Compiler output                               */
/*-----------------------------------------------*/
#include "global.h"

emit(int t, int tval) {
  switch(t) {
  case '+': 
  case '-': 
  case '*': 
  case '/':
    printf("%c \n", t); 
    break;
  case '=':
  printf(":=\n");
    break;  
  case DIV:
    printf("DIV \n"); 
    break;
  case MOD:
    printf("MOD \n"); 
    break;
  case IF:
    printf("Conditional Statement -> if\n");
    break;
  case THEN:
    printf("Conditional Statement -> then\n");
    break;
  case WHILE:
    printf("Loop -> while\n");
    break;
  case DO:
    printf("Loop -> do\n");
    break;
  case BEGIN:
    printf("This is the -> BEGIN\n");
    break;
  case END:
    printf("This is the -> END\n");
    break;                      
  case NUM:
    printf("%d \n", tval); 
    break;
  case ID:
    printf("%s \n", symtable[tval].lexptr); 
    break;
  default:
    printf("token %d, tokenval %d \n", t, tval);
    break;
  }
}