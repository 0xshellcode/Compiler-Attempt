/*-----------------------------------------------*/
/* Parser                                        */
/*-----------------------------------------------*/

#include "global.h"

int lookahead;

/* Parse Input */
parse() {
  lookahead = lexan();
  while (lookahead != DONE) { // DONE = 265
    prop();
    expr(); 
    match (';');
    printf("\n"); 
  }
}

/* Parse nonterminal expr */
expr() {
  int t;
  term();
  while(1) {
    switch(lookahead) {
    case '+': 
    case '-':
    case '=':
      t = lookahead;
      match(lookahead); 
      term(); 
      emit(t,NONE);
      break;
    default:
      return;
    }
  }
}

/* Parse nonterminal term */
term() {
  int t;

  factor();
  while(1) {
    switch(lookahead) {
      case '*': 
      case '/': 
      case DIV: 
      case MOD:
        t = lookahead;
        match(lookahead); 
        factor(); 
        emit(t,NONE);
        break;
      default:
        return 0;
    }
  }
}

/* Parse nonterminal factor */
factor() {
  switch(lookahead) {
  case '(':
    match ('('); 
    expr(); 
    match (')'); 
    break;
  case NUM:
    emit(NUM,tokenval);
    match(NUM); 
    break;
  case ID:
    emit(ID,tokenval);
    match(ID);
    break;
  default:
    error("Syntax Error In Factor!");
  }
}

prop(){
  switch (lookahead){
    case IF:
      match(IF);
      expr();
      emit(IF,tokenval); // Print IF
      match(THEN);
      emit(THEN,tokenval); // Print THEN
      prop();
    break;
    case WHILE:
      match(WHILE);
      expr();
      emit(WHILE,tokenval); // Print WHILE
      match(DO);
      emit(DO,tokenval);  // Print DO
      prop();
    break;
  case BEGIN:
    match(BEGIN);
    prop();
    emit(BEGIN, tokenval);
    break;
  case END:
    exit(0);
    break;
  default:
    asm("nop");
    break;
  }
}

/*opc_props(){
  prop_list();
  return;
}

prop_list(){
  prop();
}*/



match(int t) {
  if (lookahead==t) {
    lookahead = lexan(); // Lexer.c 
  }
  else 
    error("Syntax Error In The Match");
}

