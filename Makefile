CFLAGS = -Wall -Wextra -g

all : day1a day1b day2a

day1a : day1a.c advent.o
	mkdir -p dist
	cc -c day1a.c
	cc day1a.o advent.o $(CFLAGS) -o ./dist/day1a 

day1b : day1b.c advent.o
	mkdir -p dist
	cc -c day1b.c
	cc day1b.o advent.o $(CFLAGS) -o ./dist/day1b 

day2a : day2a.c advent.o
	mkdir -p dist
	cc -c day2a.c
	cc day2a.o advent.o $(CFLAGS) -o ./dist/day2a 

advent.o : advent.c advent.h
	cc -c advent.c $(CFLAGS)
clean :
	rm -fr ./dist *.o
