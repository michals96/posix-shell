#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "globals.h"
#include "functions.h"

#define OPTION_FOUND 1
#define OPTION_NOT_FOUND 0
#define TRUE 1
#define OPTIONS 4

char *line_of_text = NULL, current_directory[1024];
char *FUNCTION[4] = {"<", ">", "|", "&"};
char *tmp_pointer = NULL, *home_dir;
char **input_arguments;
int ifFoundFlag = 0;
int it, iterator = 0;

int main() 
{
    globals value;

    home_dir = getenv("HOME");
    
    while(1)
    {
        ssize_t size = 0;
    
        if(getcwd(current_directory, sizeof(current_directory)) != NULL)  
        {
            printf("\n[%s]#", current_directory);
        } 

        getline(&line_of_text, &size, stdin);
        
        input_arguments = parser(line_of_text); 

        char *first_input_cmd = input_arguments[0];
        char *second_input_cmd = input_arguments[1];

        // If no command was given
        if(first_input_cmd == NULL) 
        {
            free(line_of_text);
            free(input_arguments);
            continue;
        } 

        // Handle "exit" command
        if(strcmp(first_input_cmd,"exit") == 0)    
        {
            break;
        }    

        // Handle "cd" command
        else if(strcmp(first_input_cmd,"cd") == 0)
        {  
            if(second_input_cmd == NULL) 
            {              
                if(home_dir[0] != 0) 
                {               
                    chdir(home_dir);
                }
            }
            else 
            {
                chdir(first_input_cmd);
            }
        }

        // Handle other comments
        else
        {
            it = 1;

            while(input_arguments[it] != NULL) 
            {           
                for(iterator = 0; iterator < OPTIONS; iterator++) 
                {
                    if(strcmp(input_arguments[it],FUNCTION[iterator]) == 0) 
                        break;
                }

                // One of OPTIONS was found
                if(iterator < OPTIONS) 
                {
                    ifFoundFlag = OPTION_FOUND;

                    if(iterator < 3 && input_arguments[it+1] == NULL) 
                    {   
                        break;
                    }

                    // IORedirection
                    if(iterator < 2)
                    {
                        break;
                    }                         

                    // Pipe
                    else if(iterator == 2)
                    {
                        break;
                    }

                    // Run in background  
                    else if(iterator == 3)
                    {
                        process_executor(it, input_arguments); 
                    }
                                   
                    break;
                }

                it++;
            }

            // If IO/Pipe/Background was not found
            // than handle other commands for instance "ls"
            if(ifFoundFlag == OPTION_NOT_FOUND)
            {
                process_executor(0, input_arguments);      
            }

        }

        free(line_of_text);
        free(input_arguments);

    } 
} 