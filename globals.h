#ifndef GLOBALS_H
#define GLOBALS_H

#include <sys/types.h>

typedef struct globals
{
    char *directory;
    char current_directory[1024];
    char *line_of_text;
    char **arguments;

    char **tokens_array;
    char *single_token;
    
    ssize_t size_of_line;

    int bufsize;
    
} globals;

#endif