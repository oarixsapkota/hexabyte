#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "lexical.h"
#include "hexlib.h"

long globleindex = 0;

void lexical(char *content) {
  char current = content[globleindex];

  while (current != '\0') {

    debugf("Current char : %c\n", current);

    if ( current == '<') {
      globleindex = skipcomment(current,content,globleindex);
    }

    globleindex++;
    current = content[globleindex];
  }
}

long skipcomment(char current, char *content, long globleindex) {
  globleindex++;
  current = content[globleindex];

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
  }

  debugf("Return globleindex : %lu\n", globleindex);

  return globleindex;
}
