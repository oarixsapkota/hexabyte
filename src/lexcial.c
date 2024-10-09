#include <stdio.h>
#include <ctype.h>
#include "lexical.h"

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
    index++;
    current = content[index];
    printf("%c",current);
  }

  printf("\n");

  return index;
}

int isSymbol(char c) {
  if (!isalpha(c) && !isdigit(c) && !isspace(c)) {
    return 1;
  }
  return 0;
}
