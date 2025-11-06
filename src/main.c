#include <stdio.h>
#include "readFile.h"
#include "listFile.h"
#include "createFile.h"


int main(int argc, char** argv)
{   
    if(argc>1)
    {
        if(strcmp(argv[1], "read") == 0 )
        {
            char fileName[32];
            printf("What file do u want to read? \n");
            scanf("%31s", fileName);
            read_file(fileName);
        }
        else if (strcmp(argv[1], "list") == 0)
        {
            show_dir_content(".", 0);
        }

        else if (strcmp(argv[1], "create") == 0)
        {   
            
            char fileName[32];
            printf("Enter the name of file: \n");
            if(fgets(fileName, sizeof(fileName), stdin) != NULL)
            {
                fileName[strcspn(fileName, "\n")] = '\0';
            }
            
            char path[64];
            printf("\nEnther the path to file (if in your current directory press ENTER): \n");
            if(fgets(path, sizeof(path), stdin) != NULL)
            {
                path[strcspn(path, "\n")] = '\0';
            }

            create_file_action(fileName, path);
        }

    }
    return 0;
}