#ifndef _TYPE_H
#define _TYPE_H

/* token type enum */

typedef enum {
  literal,
  keyword,
  seprator,
} tokentype;

/* token type struct */

typedef struct {
  tokentype type;
  long index;
} token;

/* file type struct */

typedef struct {
  char *content;
  long length;
  int linecount;
} filedata;

#endif
