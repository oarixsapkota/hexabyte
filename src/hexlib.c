#include "hexlib.h"
#include <ctype.h>

void errf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stderr, "\033[1;31mERROR: ");
  vfprintf(stderr, format, args);
  fprintf(stderr, "\033[0m");
  va_end(args);
}

void warnf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stderr, "\033[1;34mWARNING: ");
  vfprintf(stderr, format, args);
  fprintf(stderr, "\033[0m");
  va_end(args);
}

void debugf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stderr, "\033[0;35m");
  vfprintf(stderr, format, args);
  fprintf(stderr, "\033[0m");
  va_end(args);
}

int isSymbol(char c) {
  if (!isalpha(c) && !isdigit(c) && !isspace(c)) {
    return 1;
  }
  return 0;
}