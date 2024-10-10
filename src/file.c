#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  for(int i = 0; i < length; i++) {
    buffer[i] = current;
    current = fgetc(file);
  }

  buffer[length] = '\0';

  fclose(file);

  retfile.content = buffer;
  retfile.length = length;

  return retfile;

}

void wrtfile(char *filename, char *buffer) {
  FILE *file = fopen(filename, "wb");

  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fseek(file, 0, SEEK_END);

  size_t result = fwrite(buffer, sizeof(char), strlen(buffer), file);

  if (result != strlen(buffer)) {
    perror("Error writing to file");
    fclose(file);
    exit(1);
  }

  fclose(file);
}
