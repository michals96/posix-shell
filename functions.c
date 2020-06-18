#include "functions.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

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