COMP=g++
CFLAGS=-Wall -Werror -ansi -pedantic

all:
	$(COMP) $(CFLAGS) src/main.cpp -o rshell
	mkdir bin
	mv rshell bin
rshell:
	$(COMP) $(CFLAGS) main.cpp -o rshell
	mkdir bin
	mv rshell bin

clean:
	rm -rf bin

#need to add dependancies still!!
# DO NOT USE MAKEFILE YET
