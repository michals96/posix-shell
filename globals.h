#ifndef GLOBALS_H
#define GLOBALS_H
#include <sys/types.h>

// This typedef structer was created to hold all global values which were
// meant to be used in this project. However it caused a lot of seg-faults
// so the only place were it is actually used is parser

typedef struct globals
{
    char *directory;
   
    char **arguments;

    char **tokens_array;
    char *single_token;

    ssize_t size_of_line;

    int bufsize;
    
} globals;

#endif

