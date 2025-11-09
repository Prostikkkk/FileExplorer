#include <stdio.h>
#include "readFile.h"
#include "listFile.h"
#include "createAndWriteFile.h"

void ReadPath(char *path, size_t size)
{
    printf("Enter the path or the name of file\n");
    fflush(stdout);
    if(fgets(path, size, stdin) != NULL)
    {
        size_t len = strlen(path);
        if(len > 0 && path[len-1] == '\n')
        {
            path[len - 1] = '\0';
        }
    }
    return;
}

int main(int argc, char** argv)
{   
    if(argc>1)
    {   

        /* READ FUNCTION */
        if(strcmp(argv[1], "read") == 0 )
        {   
            char path[64];
            ReadPath(path, sizeof(path));
            read_file(path);
        }
        /* LIST FUNCTION */
        else if (strcmp(argv[1], "list") == 0)
        {   
            char path[64];
            char* mode = argv[2] ? argv[2]: "-c";
            ReadPath(path, sizeof(path));
            show_dir_content(".", 0, mode);
        }
        /* CREATE FUNCTION */
        else if (strcmp(argv[1], "create") == 0)
        {   
            
            char path[64];
            ReadPath(path, sizeof(path));
            create_file_action(path);
        }
        /* WRITE FUNCTION */
        else if (strcmp(argv[1], "write")==0)
        {       
            char path[64];
            char* mode = argv[2] ? argv[2]: "-rw";
            ReadPath(path, sizeof(path));
            write_rewrite_action(path, mode);
        }
        /* DELETE FUNCTION */
        else if (strcmp(argv[1], "delete") == 0)
        {   
            char path[64];
            ReadPath(path, sizeof(path));
            remove(path);
        }

        /* FIND FUNCTION*/
        else if(strcmp(argv[1], "find")==0)
        {
            char fileName[64];
            ReadPath(fileName, sizeof(fileName));
            char* answer = find_path(fileName, "./");
            if(answer) 
            {
                printf("%s\n", answer);
                free(answer);
            }
            else printf("PATH WASN'T FOUND\n");
        }

    }
    return 0;
}