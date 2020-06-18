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
    int it = 0;
    pid_t pid, wpid;

    int status;

    if(it > 0)
    {
        arguments[it] = NULL;
    }

    pid = fork();
    
    if(pid == 0)         
    {
        execvp(arguments[0], arguments);

        if(it == 0)
        {
            exit(1);
        }
    }
    if(it == 0) 
    {
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } 
        
    }
    else {
        fprintf(stderr, "RUNNING IN BACKGROUND");
        wpid = waitpid(-1, &status, WNOHANG);
    }

}