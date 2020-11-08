CC = gcc
CFLAGS = -ggdb -O0 -mips32 -Wall -Werror

# Cambiar nombre del target cuando se modifique el ejecutable
TARGET = common

all: $(TARGET)

$(TARGET): main.o mcd_euclides.o mcm_euclides.o
	$(CC) main.o mcd_euclides.o mcm_euclides.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

mcd_euclides.o: mcd_euclides.S
	$(CC) $(CFLAGS) -c mcd_euclides.S -o mcd_euclides.o

mcm_euclides.o: mcm_euclides.S
	$(CC) $(CFLAGS) -c mcm_euclides.S -o mcm_euclides.o

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
