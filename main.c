#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct globals
{
    char *directory;
    char current_directory[1024];
    
} globals;

int main()
{
    globals value;

    while(1)
    {
        if(getcwd(value.current_directory, sizeof(value.current_directory)) != NULL)
            printf("\n%s ", value.current_directory);
    }
    
    return 0;
}

