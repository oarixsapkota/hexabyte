#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _HEXLIB_H
#define _HEXLIB_H

void errf(const char *format, ...);
void warnf(const char *format, ...);
void debugf(const char *format, ...);
int isSymbol(char c);
int isflag(char *string);
int getflagtype(char *string);

#endif
