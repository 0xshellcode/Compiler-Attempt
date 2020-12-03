#include "global.h"


error(char *m) {
  fprintf(stderr, "ERROR: line %d:%s\n", lineno, m);
  printf("\nInterrupted.\n");
  exit(1); 

}