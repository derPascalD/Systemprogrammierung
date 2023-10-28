CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

## $@ = zooProgramm
## CFLAGS = -g - Wall -ansi -pedantic

.PHONY: all
all: testCompile


testCompile: testProgramm.h testProgramm.c testMain.c
	$(CC) -ansi -Wall -pedantic -o testP $^


runTest: testCompile
	./testP

clean:
	rm -rf testP
	

