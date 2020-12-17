CC = gcc
CFLAGS = -g -std=c99 -Wall -Wno-sign-conversion -Werror 
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

EXEC_S = main

CFILES = main.c strutil.c address_parser.c cache.c memory.c parsers.c
HFILES = strutil.h address_parser.h cache.h memory.h parsers.h

build: $(CFILES)
	$(CC) $(CFLAGS) -o $(EXEC_S) $(CFILES)

run: build
	./$(EXEC_S)

valgrind: build
	valgrind $(VFLAGS) ./$(EXEC_S)

clean:
	rm -f *.o $(EXEC_S)
