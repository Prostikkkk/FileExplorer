#include "readFile.h"

char* get_file_type(char* file)
{
    char* fileType = strchr(file, '.');
    if(!fileType || fileType == file) return "???";
    return fileType + 1;
}


void read_file(char* fileName)
{   
    FILE* fptr; 
    fptr = fopen(fileName, "r");
    
    if(fptr == NULL)
    {
        printf("The file is not opened");
        return;
    }
    else
    {   
        fseek(fptr, 0L, SEEK_END);
        long res = ftell(fptr);
        printf("______________________________________________________________________________________\n"
                "|\tFile : %s\t|\tSize of file is : %ld \t|\tType: %s\n"
                "______________________________________________________________________________________\n", fileName, res, get_file_type(fileName));
        fseek(fptr, 0L, SEEK_SET);
        char myString[5];
        printf("The data is: \n");
        while(fgets(myString, sizeof(myString), fptr) != NULL)
        {
            printf("%s", myString);
        }
        printf("\n");
    }
    fclose(fptr);
}