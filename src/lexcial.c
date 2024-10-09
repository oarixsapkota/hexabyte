#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "lexical.h"
#include "hexlib.h"

void lexical(char current, char *content, long index) {
  while (current != '\0') {
    if ( current == '<') {
      index = skipcomment(current,content,index);
      printf("return index : %lu\n", index);
    } else if (isalpha(current)) {
      printf("Found Alpha  : %c\n", current);
    } else if (isdigit(current)) {
      printf("Found Digit  : %c\n", current);
    } else if (isSymbol(current)) {
      printf("Found Symbol : %c\n", current);
    }

    index++;
    current = content[index];
  }
}

long skipcomment(char current, char *content, long index) {
  printf("\nfound comment: %c",current);

  index++;
  current = content[index];

  printf("%c",current);

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
    index++;
    current = content[index];
    printf("%c",current);
  }

  printf("\n");

  return index;
}
