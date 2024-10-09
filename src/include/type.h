#ifndef _TYPE_H
#define _TYPE_H

/* token type enum */

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

/* token type struct */

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

typedef struct {
  tokenliteral literal;
  tokenseprator seprator;
  tokenkeyword keyword;
  long index;
} token;

/* file type struct */

typedef struct {
  char *content;
  long length;
  int linecount;
} filedata;

#endif
