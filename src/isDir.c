#include "isDir.h"

int isDir(const char* fileName)
{

    struct stat statbuf;
    if (stat(fileName, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}