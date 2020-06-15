# Makefile for building app
# @author Michal Stefaniuk

CC_C = gcc

all:
	$(CC_C) *c *h -o posix

run:
	./posix

clean:
	rm -f posix *h.gch
