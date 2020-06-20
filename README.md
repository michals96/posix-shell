# posix-shell
*Programming in UNIX systems 202*0  
**Michal Stefaniuk**  
## Project target
Simple shell allowing to run other programs

## How to run

* `make` to build the project

* `make run` to run the project

* `make clean` to clean the project

## Supported features

* `cd`

* `exit`

* `pipe`

* `IORedirection`

* `background processing`

* All linux commands that could be executed in one argument

## Example commands

* `cd ..`

* `cd directory_name`

* `exit`

* `ls > file.txt`

* `cat file.txt | head -1`

* `sort file.txt | uniq `

* `ls &`

* `ps` - to see if above was run in background (defunct mode)
