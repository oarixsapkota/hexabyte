#include <stdio.h>
#include <stdlib.h>
#include "file.h"


int main(int argv,char **argc) {
  printf("%s",rdfile(argc[1]));
  return 0;
}
