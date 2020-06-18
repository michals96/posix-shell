#ifndef FUNCTIONS_H
#define FUNCTIONS_H

char **handle_arguments(int type, char **arguments);

void process_executor(int type, char**arguments);

/* This function will take command line as input and 
it will split it into tokens for example
Input : Hello world!
output {"Hello", "world!"} */
char **parser(char *str);

#endif