# Makefile for building app
# @author Michal Stefaniuk

CC_C = gcc

all:
	$(CC_C) -g  *c *h -o posix -Wimplicit-function-declaration

run:
	./posix

clean:
	rm -f posix *h.gch
