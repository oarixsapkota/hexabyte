#include <stdio.h>
#include <ctype.h>
#include "lexical.h"

void lexical(char current, char *content, long index) {
  while (current != '\0') {
    if (current == '#') {
      index = skipcomment(current,content,index);
      current = content[index];
    }
    index++;
    current = content[index];
  }
}

long skipcomment(char current, char *content, long index) {
  printf("found comment: %c",current);
  index++;
  current = content[index];
  printf("%c",current);
  while (current != '#') {
    index++;
    current = content[index];
    printf("%c",current);
  }
  printf("\n");
  return index;
}
