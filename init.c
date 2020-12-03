#include "global.h"

// Defining Keywords Structure

struct entry keywords[] = {
    "div", DIV,
    "mod", MOD,
    "if", IF,
    "then", THEN,
    "while", WHILE,
    "do", DO,
    "begin", BEGIN,
    "end", END,
    0, 0
};

init(){ /* Load the keywords in the symbol tables*/
  struct entry *p; // Declaring structure

  for (p = keywords; p->token; p++){ // -> Dereference the pointer and access to the specified field
    insert(p->lexptr, p->token); // This function is in symbol.c
  }
}