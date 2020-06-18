#ifndef PARSER_H
#define PARSER_H

/* This function will take command line as input and 
it will split it into tokens for example
Input : Hello world!
output {"Hello", "world!"} */
char **parser(char *str);

#endif