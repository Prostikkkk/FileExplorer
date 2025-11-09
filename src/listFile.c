#include "listFile.h"
#include "isDir.h"


void show_dir_content(char *path, int arg1, char* mode)

{   

    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    
    if(!d)  return;
    

    while((dir = readdir(d)) != NULL)
    {   
        if ((strcmp(dir->d_name, ".") == 0) || (strcmp(dir->d_name, "..")== 0)) continue;
        for (int j = 0; j < arg1 - 1; j++)
        {
            printf("\t");
        }
        if (arg1 > 0) printf("|-----> ");
        
        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, dir->d_name);
        
        printf("%s\n", dir->d_name);

        if(isDir(fullpath) && strcmp(mode, "all") == 0)
        {
            show_dir_content(fullpath, arg1+1, mode);
        }

    }
    closedir(d);
    return;
}

char* find_path(char* find, char* directory)
{
    DIR *d = opendir(directory);
    if (!d) return NULL;
    
    struct dirent *dir;
    while ((dir = readdir(d)) != NULL)
    {
        if ((strcmp(dir->d_name, ".") == 0) || (strcmp(dir->d_name, "..")== 0)) continue;
        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s%s%s",
                directory,
                (directory[strlen(directory) - 1] == '/') ? "" : "/",
                dir->d_name);

        if(strcmp(dir->d_name, find) == 0)
        {   
            closedir(d);
            char* copy = malloc(strlen(fullpath) +1);
            if(copy) strcpy(copy, fullpath);
            return  copy;
        }
        if(isDir(directory))
        {
            char *result = find_path(find, fullpath);
            if(result)
            {
                closedir(d);
                return result;
            }
        }
        
    }
    closedir(d);
    return NULL;
}