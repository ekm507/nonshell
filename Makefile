
# nonshell is a shell-like program that does nothing

CC=gcc
# CFLAGS = -g -lreadline -Wall  
all:
	if [ ! -d "./build/" ];	then mkdir build; fi
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o
	$(CC) $(CFLAGS) build/main.o -o noshell

clean:
	rm build/main.o
	rmdir build