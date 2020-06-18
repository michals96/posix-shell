#include "functions.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "globals.h"

char **handle_arguments(int type, char **arguments)
{
    int it = 0;
    char **tmp = malloc(sizeof(char *) *(type +1));

    for(it = 0; it < type; ++it)
    {
        tmp[it] = strdup(arguments[it]);
    }

    tmp[it] = 0;

    return tmp;
}

void process_executor(int type, char**arguments)
{
    pid_t pid, wpid;
    int status;

    if(type > 0)
    {
        arguments[type] = NULL; 
    }

    pid = fork();

    if(pid == 0)          
    {
        execvp(arguments[0], arguments);
        perror("Program execution failed");
        if(type == 0)
            exit(1);
    }
    if(type == 0) 
    {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } 
        while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else 
    {
        fprintf(stderr,"\n");
        fprintf(stderr, "RUNNING IN BACKGROUND");
        fprintf(stderr, "\n");
        wpid = waitpid(-1, &status, WNOHANG);
    }
}

#define SIZE_OF_TOKEN 64
#define TOKENS " \t\r\n\a"

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