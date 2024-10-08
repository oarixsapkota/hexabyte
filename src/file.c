#include <stdio.h>
#include <stdlib.h>
#include "file.h"

char *rdfile(char *filename) {
  FILE *file = fopen(filename, "rb");

  if (file == NULL) {
    perror("Error opening file");
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

  for(int i = 0; i < length; i++) {
    buffer[i] = current;
    current = fgetc(file);
  }

  fclose(file);

  return buffer;

}