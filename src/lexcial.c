#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "lexical.h"
#include "hexlib.h"

long globleindex = 0;

void lexical(char *content) {
  char current = content[globleindex];

  while (current != '\0') {
    if ( current == '<') {
      globleindex = skipcomment(current,content,globleindex);
    } else if (isalpha(current)) {
      printf("Found Alpha  : %c\n", current);
    } else if (isdigit(current)) {
      printf("Found Digit  : %c\n", current);
    } else if (isSymbol(current)) {
      printf("Found Symbol : %c\n", current);
    }

    globleindex++;
    current = content[globleindex];
  }
}

long skipcomment(char current, char *content, long globleindex) {
  debugf("found comment: %c",current);

  globleindex++;
  current = content[globleindex];

  debugf("%c",current);

  while (current != '>') {
    switch (current) {
      case '\0':
        errf("Comment not closed properly\n");
        free(content);
        exit(2);
      case '<':
        errf("Comment not closed properly\n");
        free(content);
        exit(2);
    }
    globleindex++;
    current = content[globleindex];
    debugf("%c",current);
  }

  debugf("\nreturn globleindex : %lu\n", globleindex);

  return globleindex;
}
