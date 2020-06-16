#include "parser.h"
#include "globals.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define SIZE_OF_TOKEN 64
#define TOKENS " \t\r\n\a"

/* This function will take command line as input and 
it will split it into tokens for example
Input : Hello world!
output {"Hello", "world!"} */

char **parser(char *str)
{
    globals value;

    value.bufsize = 64;
    int l = 0;

    value.tokens_array = malloc(SIZE_OF_TOKEN * sizeof(char*));

    value.single_token = strtok(str, TOKENS);

    while(value.single_token != NULL)
    {
        value.tokens_array[l] = value.single_token;
        l++;

        if (l >= value.bufsize)
        {
            value.bufsize += SIZE_OF_TOKEN;
            value.tokens_array = realloc(value.single_token, value.bufsize * sizeof(char*));

        }

        value.single_token = strtok(NULL, TOKENS);
    }

    value.tokens_array[l] = NULL;

    // For debugging purposes
    //printf("%s %s %s", value.tokens_array[0], value.tokens_array[1], value.tokens_array[2]);
    
    return value.tokens_array;
}