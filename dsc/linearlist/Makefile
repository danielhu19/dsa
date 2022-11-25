.PHONY: run clean

CFLAGS = -Wall -Werror -std=c11 -O2 -g
CC = gcc
LD = gcc

linearlist: linearlist.o main.o
		$(LD) -o linearlist linearlist.o main.o

linearlist.o: linearlist.c linearlist.h
		$(CC) $(CFLAGS) -c -o linearlist.o linearlist.c

main.o: main.c linearlist.h
		$(CC) $(CFLAGS) -c -o main.o main.c

run: linearlist
		@./linearlist

clean:
		rm -rf *.o linearlist
