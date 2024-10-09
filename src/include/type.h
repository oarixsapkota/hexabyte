#ifndef _TYPE_H
#define _TYPE_H

typedef enum {
  EXIT,
} typekeyword;

typedef enum {
  oPren,
  cPren,
} typeseprator;

typedef enum {
  INT,
} typeliteral;

typedef struct {
  typekeyword type;
} tokenkeyword;

typedef struct {
  typeseprator type;
} tokenseprator;

typedef struct {
  typeliteral type;
  int value;
} tokenliteral;

/* file type def */

typedef struct {
  char *content;
  long length;
  int linecount;
} filedata;

#endif
