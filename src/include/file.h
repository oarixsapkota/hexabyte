#ifndef _FILE_H
#define _FILE_H

typedef struct {
    char *content;
    long length;
    int linecount;
} filedata;

filedata rdfile(char *filename);

#endif
