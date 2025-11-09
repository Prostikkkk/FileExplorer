#ifndef LIST_FILE_H
#define LIST_FILE_H

#include <sys/types.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void show_dir_content(char*, int, char*);
char* find_path(char* path, char* dir);

#endif