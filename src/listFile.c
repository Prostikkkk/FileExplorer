#include "listFile.h"
#include "isDir.h"


void show_dir_content(char *path, int arg1)

{   

    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    
    if(!d)
    {   
        return;
    }

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

        if(isDir(fullpath))
        {
            show_dir_content(fullpath, arg1+1);
        }

    }
    closedir(d);
    return;
}