SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

## $@ = zooProgramm
## CFLAGS = -g - Wall -ansi -pedantic

.PHONY: all
all: zooProgramm

zooProgramm: $(OBJS)
	$(CC) -o $@ $^

createDocFolder:
	mkdir doc/

.PHONY: install
install: all programmFolder
	mv zooProgramm programmFolder/

programmFolder:
	mkdir programmFolder/

document: createDocFolder
	cd doc;doxygen -g

.PHONY: doc
doc: document
	cd doc;doxygen Doxyfile

.PHONY: test
test: 
	cd test; make runTest
	
#alle .c zu einer .o kompilieren 
# $< steht für die erste abhängigkeit %.c = $<
%.o: %.c zoo.h
	$(CC) $(CFLAGS) -c $<

.PHONY: run
run: install
	./programmFolder/zooProgramm


.PHONY: clean
clean:
	rm -rf mytest $(OBJS)

.PHONY: distclean
distclean: clean
	rm -rf programmFolder doc



