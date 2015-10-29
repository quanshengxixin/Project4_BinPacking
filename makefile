CFLAGS = -g -Wall
CC = gcc

objects = Greedy.o Item.o Bin.o main.o

main: $(objects)
	gcc -g -Wall -o main $(objects)

Bin.o:		Bin.c Bin.h
Item.o:		Item.c Item.h
Greedy.o: 	Greedy.c Greedy.h
main.o: 	main.c Bin.h Greedy.h Item.h

.PHONY : clean
clean: 
	rm main $(objects)
