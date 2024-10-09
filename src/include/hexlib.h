#include <stdarg.h>
#include <stdio.h>

#ifndef _HEXLIB_H
#define _HEXLIB_H

void errf(const char *format, ...);
void warnf(const char *format, ...);
int isSymbol(char c);

#endif
