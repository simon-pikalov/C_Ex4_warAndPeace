CC = gcc
CFLAGS = -Wall -g
DEPS1 = trie.h

%trie.o: %trie.c $(DEPS1)
	$(CC) -c $< $(CFLAGS)

%main.o: %main.c $(DEPS1)
	$(CC) -c $< $(CFLAGS)

all: frequency 

frequency: main.c trie.c
	$(CC) -c -Wall main.c trie.c 
	$(CC) -o frequency main.o trie.o

.PHONY: clean

clean:
	rm -f *.o *.out frequency
