#ifndef LIST_FILE_H
#define LIST_FILE_H

#include <sys/types.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int isDir(const char*);
void show_dir_content(char*, int);

#endif