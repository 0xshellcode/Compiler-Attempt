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
  case '<':
  case '>':
    printf("[*] %c [*]\n", t); 
    break;
  case '=':
  printf("[*] := [*]\n");
    break;  
  case DIV:
    printf("[*] DIV [*]\n"); 
    break;
  case MOD:
    printf("[*] MOD [*]\n"); 
    break;
  case IF:
    printf("[*] Proposition -> If [*]\n");
    break;
  case THEN:
    printf("[*] Proposition -> Then [*]\n");
    break;
  case WHILE:
    printf("[*] Proposition: Loop -> While [*]\n");
    break;
  case DO:
    printf("[*] Proposition: Loop -> Do [*]\n");
    break;
  case BEGIN:
    printf("[+] BEGIN [+]\n");
    break;
  case END:
    printf("[-] END [-]\n");
    break;                      
  case NUM:
    printf("[*] %d [*]\n", tval); 
    break;
  case ID:
    printf("[*] %s [*]\n", symtable[tval].lexptr); 
    break;
  default:
    printf("token %d, tokenval %d \n", t, tval);
    break;
  }
}
