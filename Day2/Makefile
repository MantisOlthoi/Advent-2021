CC=gcc

all: day2.1 day2.2

day2.1: main.c helper.h Makefile
	$(CC) -o $@ $< -O0 -g

day2.2: main2.2.c helper.h Makefile
	$(CC) -o $@ $< -O0 -g

clean:
	rm -f day2.1 day2.2
