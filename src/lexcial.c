#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "lexical.h"
#include "hexlib.h"

long globleindex = 0;

char *getword(char *content) {
  char current = content[globleindex];
  char *word = malloc(sizeof(char)*8);
  for (int i = 0; i < 8; i++) {
    if (!isalpha(current)) {
      break;
    }
    word[i] = current;
    globleindex++;
    current = content[globleindex];
    word[i + 1] = '\0';
  }
  return word;
}

void lexical(char *content) {
  char current = content[globleindex];

  while (current != '\0') {
    if ( current == '<') {
      globleindex = skipcomment(current,content,globleindex);
    } else if (isalpha(current)) {
      char *word = getword(content);
      printf("Found Word   : %s\n", word);
      free(word);
    } else if (isdigit(current)) {
      printf("Found Digit  : %c\n", current);
    } else if (isSymbol(current)) {
      printf("Found Symbol : %c\n", current);
    } else if (current == '\n') {
      warnf("Found new line char\n");
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
