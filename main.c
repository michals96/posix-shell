#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "parser.h"
#include "globals.h"

#define OPTION_FOUND 1
#define OPTION_NOT_FOUND 0
#define TRUE 1
#define OPTIONS 4

char *line_of_text = NULL, current_directory[1024];
const char *FUNCTION[4] = {"<", ">", "|", "&"};

int main()
{
    globals value;

    while(1)
    {
        if(getcwd(current_directory, sizeof(current_directory)) != NULL)
            printf("\n%s ", current_directory);
        
        getline(&line_of_text, &value.size_of_line, stdin);

       value.arguments = parser(line_of_text);

        char *first_input_cmd = value.arguments[0];
        char *second_input_cmd = value.arguments[1];

        if(strcmp(first_input_cmd, "exit") == 0) // EXIT
        {
            break;
        }

        if(strcmp(first_input_cmd, "cd") == 0) // CD
        {
            if(second_input_cmd == NULL && getenv("HOME") == NULL)
            {
                chdir(getenv("HOME"));
            }
            else
            {
                chdir(second_input_cmd);
            }
            
        }

        else
        {
            int k = 1;
            int i = 0;
            int ifFoundFlag = 0;
            //while(value.arguments[k] != NULL) {
            while(value.arguments[k] != OPTION_NOT_FOUND)
            {
                for( i=0; i<4; ++i)
                {
                    if(strcmp(value.arguments[k], FUNCTION[i]) == 0)
                    {
                        break;
                    }
                }

                if(i < OPTIONS)
                {
                    ifFoundFlag = OPTION_FOUND;

                    if( i<3 && value.arguments[k+1] == NULL) //missing arg for IOR or Pipe
                    {
                        break;
                    }

                    if(i<2)
                    {
                        break; // Ioredirect
                    }

                    if(i==2)
                    {
                        break; // pipe
                    }

                    if(i==3)
                    {
                        break; // Background proces
                    }

                    break;
                }
                k++;
            }
            if(ifFoundFlag == OPTION_NOT_FOUND)
                break; // start background process
        }
        free(line_of_text);
        free(value.arguments);
    }
    return 0;
}

