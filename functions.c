#include "functions.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int it = 0;

char **handle_arguments( int type, char **arguments)
{
    char **tmp = malloc(sizeof(char *) *(type +1));

    for(it = 0; it < type; ++it)
    {
        tmp[it] = strdup(arguments[it]);
    }

    tmp[it] = 0;

    return tmp;
}