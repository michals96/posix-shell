#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
    Returns a pointer to the newly allocated string carrying input args
    @param type         Works as and index to an array containing input arguments
    @param arguments    Array of input arguments
    @return             Pointer to array of arguments
*/
char **handle_arguments(int type, char **arguments);

/**
    Handles running processes by excepv in child created by fork.
    @param type         Works as and index to an array containing input arguments
    @param arguments    Array of input arguments
    @return             Type void
*/
void process_executor(int type, char**arguments);

/**
    Handles IORedirection
    @param type         Works as and index to an array containing input arguments
    @param arguments    Array of input arguments
    @return             Type void
*/
void redirect(int type, char **arguments, int input_output);

/**
    Handles piping
    @param type         Works as and index to an array containing input arguments
    @param arguments    Array of input arguments
    @return             Type void
*/
void pipeIO(int type, char **arguments);

/**
    This function will take command line as input and it will split it into tokens for example
    Input : Hello world!            Output {"Hello", "world!"} 
    @param str   Array of input arguments
    @return      Returns pointer to array of input arguments
*/
char **parser(char *str);


#endif