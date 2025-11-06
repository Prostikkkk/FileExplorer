#include <stdio.h>
#include "readFile.h"
#include "listFile.h"



int main(int argc, char** argv)
{   
    argc--;
    if(argc>0)
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
    }
    return 0;
}