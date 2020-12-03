#include "global.h"


char lexemes[STRMAX];
int lastchar = -1;
int lastentry = 0;

struct entry symtable[SYMMAX];


int lookup(char s[]) {

  for (int p = lastentry; p > 0; p = p - 1) {
    if (strcmp(symtable[p].lexptr,s)==0) { // If they are equal, the return the enteren value
      return p;
    }
  }

  return 0;
}

/* Insert new symbol into symbol strucure */
int insert(char s[], int tok) {
  int len;

  len = strlen(s); // Get length of the char

  if (lastentry+1 >= SYMMAX) { // SYMMAX = 100; 
    error ("Symbol table overflow!");
  }

  if (lastchar+len+1 >= STRMAX) { // STRMAX = 999
    error ("Lexem array overflow!");
  }

  lastentry++; // One step
  symtable[lastentry].token = tok;
  symtable[lastentry].lexptr = &lexemes[lastchar+1]; // Address Memory
  lastchar = lastchar + len + 1;
  strcpy(symtable[lastentry].lexptr, s); // Copy s to symbol table position, Insecure function but is protected by the previous if's

  return lastentry;
}