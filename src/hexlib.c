#include "hexlib.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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
  fprintf(stderr, "\033[1;35mWARNING: ");
  vfprintf(stderr, format, args);
  fprintf(stderr, "\033[0m");
  va_end(args);
}

void debugf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stderr, "\033[0;34mINFO: ");
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

int isflag(char *string) {
  if (string[0] == '-') {
    return 1;
  }

  return 0;
}

/*
-f : 9 : input file
-c : 8 : conpile file
-o : 7 : output file
*/

int getflagtype(char *string) {
  switch (string[1]) {
    case 'f':
      return 9;
    case 'c':
      return 8;
    case 'o':
      return 7;
  }

  errf("Invalid argument %s\n",string);
  exit(1);
}