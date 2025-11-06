#include "createFile.h"
#include "isDir.h"

void create_file_action(char* fileName, char* path)
{   
    FILE* fptr;
    if(strlen(path) > 0)
    {
        if(isDir(path))
        {   
            printf("IS DIR");
            strcat(path, fileName);
            fptr = fopen(path, "w");
        }
        else
        {
            printf("Directory wasnt found");
            return;
        }
    }
    else 
    {
        fptr = fopen(fileName, "w");
    }
    fclose(fptr);
    return;
}