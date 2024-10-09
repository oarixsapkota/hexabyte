#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "type.h"
#include "lexical.h"
#include "hexlib.h"


int main(int argv,char **argc) {

  char *inputfilename;
  char *outputfilename;

  for (int i = 1; i < argv; i++) {
    if (isflag(argc[i])) {
      int flagtype  = getflagtype(argc[i]);
      if (flagtype == 9) {
        inputfilename = argc[i + 1];
      }
      if (flagtype == 7) {
        outputfilename = argc[i + 1];
      }
    }
  }

  if (outputfilename == NULL) {
    outputfilename = "asa.temp.s";
  }

  filedata file = rdfile(inputfilename);

  lexical(file.content);

  free(file.content);
  debugf("file Length  : %lu\n",file.length);
  debugf("line count   : %d\n",file.linecount);

  return 0;
}
