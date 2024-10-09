#ifndef _FILE_H
#define _FILE_H

#include "type.h"

filedata rdfile(char *filename);
void wrtfile(char *filename, char *buffer);

#endif
