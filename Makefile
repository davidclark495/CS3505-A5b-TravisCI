#
CC = g++
CFLAGS = -Wall -std=c++11

GOOGLETEST ?= /Users/davidclark/googletest
#GOOGLETEST ?= C:\Users\zathe\github-classroom\googletest

INCLUDE = $(GOOGLETEST)/googletest/include
LFLAGS = $(GOOGLETEST)/lib


#

all: TrieTests

TrieTests: TrieTests.o Trie.o
	$(CC) $(CFLAGS) -o TrieTests TrieTests.o Trie.o -L $(LFLAGS) -lgtest -lgtest_main -lpthread

TrieTests.o: TrieTests.cpp Trie.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c TrieTests.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

clean:
	rm -f TrieTests *.o

test: 
	./TrieTests 