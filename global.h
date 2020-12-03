#pragma once
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 128
#define NONE -1
#define EOS '\0' // End of string, this is used in the symbol table

// Lexical Component Codes --> This is used bye the lexical analyzer (in this case the lexer)

#define NUM   256
#define DIV   257
#define MOD   258
#define ID    259 // Identifier, index on the symbol table
#define SEM   260

// Prepositions

#define IF     261
#define THEN   262
#define WHILE  263
#define DO     264
#define BEGIN  265
#define END    266

#define DONE  267 // End
#define STRMAX 999
#define SYMMAX 100

extern int tokenval;
extern int lineno;


// Defining Symbol Table Entry
struct entry {
     char *lexptr; // Pointer
     int  token;
};

extern struct entry symtable[SYMMAX]; // Declaring Symbol Table Entry