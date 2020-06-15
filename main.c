#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "parser.h"

typedef struct globals
{
    char *directory;
    char current_directory[1024];
    char *line_of_text;
    char **arguments;
    ssize_t size_of_line;
    
} globals;

int main()
{
    globals value;

    while(1)
    {
        if(getcwd(value.current_directory, sizeof(value.current_directory)) != NULL)
            printf("\n%s ", value.current_directory);
        
        getline(&value.line_of_text, &value.size_of_line, stdin);

       value.arguments = parser(value.line_of_text);

    }
    
    return 0;
}

