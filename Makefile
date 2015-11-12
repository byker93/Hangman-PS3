CC=gcc
CFLAGS=-std=c11 -Wall -Werror -pedantic
LIBS=-lm
NAME=hangman

all: hangman

hangman: hangman.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

hangman.o: hangman.c
	$(CC) $(CFLAGS) -c $< $(LIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c $< $(LIBS)

clean:
	rm *.o $(NAME)
