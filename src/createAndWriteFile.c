#include "createAndWriteFile.h"
#include "isDir.h"

void create_file_action(char* fileName, char* path)
{   
    FILE* fptr;
    if(strlen(path) > 0)
    {
        if(isDir(path))
        {   
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

void write_rewrite_action(const char* path, char* mode)
{   
    char* dir = (char *) malloc(strlen(path)+1);
    strcpy(dir, path);

    char *slash = strrchr(dir, '/');

    if(slash != NULL)
    {
        *slash = '\0';
    }
    else
    {
        strcpy(dir, ".");
    }
    if(isDir(dir))
    {       
        FILE* fptr;
        if(strcmp(mode, "-rw") == 0)
        {
            fptr = fopen(path, "w");
        }
        else if(strcmp(mode, "-a" )== 0) 
        {
            fptr = fopen(path, "a");
        }
        else
        {
            printf("Flag isnt corrent ");
            return;
        }

        char buffer[128];
        while(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            fputs(buffer, fptr);
        }
        fclose(fptr);
    }
    free(dir);
    return;
}