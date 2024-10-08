#include <stdio.h>
#include <stdlib.h>

int main(int argv,char **argc) {
  FILE *file = fopen(argc[1], "rb");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  unsigned char *buffer = (unsigned char *)malloc(file_size);
  if (buffer == NULL) {
    perror("Memory allocation error");
    fclose(file);
    return 1;
  }

  size_t bytes_read = fread(buffer, 1, file_size, file);
  if (bytes_read != file_size) {
    perror("Error reading file");
    free(buffer);
    fclose(file);
    return 1;
  }

  long index = 0;
  long indexa = 0;
  long indexb = 0;
  while (index < file_size) {
    for (long j = 0; j < 16 && indexa < file_size; j++) {
      printf("%02x ", buffer[indexa]);
      indexa++;
      index++;
    }
    printf("");
    for (long j = 0; j < 16 && indexb < file_size; j++) {
      printf("%c ", buffer[indexb]);
      indexb++;
    }
    printf("\n");
  }

  free(buffer);
  fclose(file);

  return 0;
}
