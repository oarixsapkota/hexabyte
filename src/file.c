#include <stdio.h>
#include <stdlib.h>
#include "file.h"

filedata rdfile(char *filename) {
  FILE *file = fopen(filename, "rb");
  filedata retfile;

  if (file == NULL) {
    perror("Error opening file");
    fclose(file);
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  rewind(file);

  unsigned char *buffer = (unsigned char *)malloc(length);
  if (buffer == NULL) {
    perror("Memory allocation error");
    fclose(file);
    exit(1);
  }

  char current = fgetc(file);
  int linecount = 1;

  for(int i = 0; i < length; i++) {
    buffer[i] = current;
    current = fgetc(file);
    if (current == '\n') {
      linecount++;
    }
  }

  buffer[length] = '\0';

  fclose(file);

  retfile.content = buffer;
  retfile.linecount = linecount;
  retfile.length = length;

  return retfile;

}
