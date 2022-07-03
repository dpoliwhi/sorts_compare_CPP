GXX=g++
FLAGS=-Wall -Wextra -Werror -std=c++17
OS=$(shell uname -s)
LINUX=-lrt -lpthread -lm -D_GNU_SOURCE

all: m clean

m: 
	$(GXX)  main.cpp sort.cpp data.cpp -o main $(FLAGS)
	./main

clean:
	rm -rf main
