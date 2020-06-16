#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "parser.h"
#include "globals.h"

char *line_of_text = NULL, current_directory[1024];

int main()
{
    globals value;

    while(1)
    {
        if(getcwd(current_directory, sizeof(current_directory)) != NULL)
            printf("\n%s ", current_directory);
        
        getline(&line_of_text, &value.size_of_line, stdin);

       value.arguments = parser(line_of_text);

    }

    return 0;
}

