#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file.h"


int main(int argv,char **argc) {
  filedata file = rdfile(argc[1]);

  printf("%s\nfile length : %ld char\nline count : %d",file.content,file.length,file.linecount);

  wrtfile("test.o",file.content);

  free(file.content);

  return 0;
}
