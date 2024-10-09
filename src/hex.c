#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "type.h"
#include "lexical.h"
#include "hexlib.h"


int main(int argv,char **argc) {
  filedata file = rdfile(argc[1]);

  long index = 0;
  char current = file.content[index];

  lexical(current, file.content, index);

  free(file.content);
  debugf("file Length  : %lu\n",file.length);
  debugf("line count   : %d\n",file.linecount);

  return 0;
}
