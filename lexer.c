/*-----------------------------------------------*/
/* Lexical Analyzer                              */
/*-----------------------------------------------*/

#include "global.h"

char lexbuf[BUFFER_SIZE]; // 128 -> Stdin Buffer

int lineno = 1;
int tokenval = NONE; // NONE = -1

int lexan() {
  int t;

  while(1) {
    t = getc(stdin); // Read Input
    if (t==' ' || t=='\t') { // Ignore blanks
      asm("nop");
    }
    else if (t=='\n') { // Increment linenumber
      lineno++;
    }
    else if (isdigit(t)) {  // t is digit
      ungetc(t,stdin); // Push t value into stdin
      scanf("%d", &tokenval); // Read next value
      return NUM;             // NUM = 256
    }
    else if (isalpha(t)) { // t is a letter
      int p, b = 0;

      while (isalnum(t)) {  /* t is alphanumeric */
        lexbuf[b] = t; // t goes into index 0
        t = getc(stdin); // Read Stdin
        b++;
        if (b >= BUFFER_SIZE) { // Buffer Overflow Protection
          error("Compiler error!");
        }
      }

      lexbuf[b]= EOS; // EOS = '\0'
      if (t != EOF) { 
        ungetc(t,stdin); // Push t into stdin
      }
      p = lookup(lexbuf); // Search for the \0 in the symbol tables
      if (p==0) {
        p = insert (lexbuf, ID); // Insert into symbol table
      }
      tokenval = p;
      return symtable[p].token; // Add token
    }
    else if (t==EOF) { // End of file
      return DONE;
    }
    else if (t==';') { // End of statement
      tokenval= SEM;
      return t;
    } else { // No token recognized
      tokenval= NONE;
      return t;
    }
  }
}