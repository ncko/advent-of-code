CFLAGS = -Wall -g

all : day1a day1b

day1a : day1a.c advent.o
	cc -c day1a.c
	cc day1a.o advent.o $(CFLAGS) -o ./dist/day1a 

day1b : day1b.c advent.o
	cc -c day1b.c
	cc day1b.o advent.o $(CFLAGS) -o ./dist/day1b 

advent.o : advent.c advent.h
	cc -c advent.c


