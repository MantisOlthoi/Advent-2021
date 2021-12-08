CC=gcc

all: day1.1 betterParse1.1 noParsing1.1 slidingWindow1.2

day1.1: main.c
	$(CC) $^ -o $@ -O3

betterParse1.1: betterParse.c
	$(CC) -o $@ $^ -O3

noParsing1.1: noParse.c input.c
	$(CC) -o $@ $^ -O3

slidingWindow1.2: slidingWindow.c input.c
	$(CC) -o $@ $^ -O3

clean:
	rm -f day1.1 betterParse1.1 noParsing1.1
