# Makefile for building app
# @author Michal Stefaniuk

CC_C = gcc

all:
	$(CC_C) main.c -o main

main:
	$(CC_C) main.c main.h -o main

run:
	./main
clean:
	rm -f main
