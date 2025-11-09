#include "createAndWriteFile.h"
#include "isDir.h"

void create_file_action(const char* path)
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
        fptr = fopen(path, "w");
        fclose(fptr);
    }
    else 
    {
        printf("The directory wanst found");
    }
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

        printf("\nPRESS CTRL + D TO EXIT\n");
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