#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#define _POSIX_C_SOURCE 200809L //para incluir getline
char* BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void printHelp();
void decode(FILE* inputFile, FILE* outputFile);
void code(FILE* inputFile, FILE* outputFile);

void codificar(char buffer[], int tamanio_buffer) {
	char _buffer[5] = "====";
	int buffer_shifteado;
	int mascaraBase;
	int caracter_binario;
	char caracter;
	int posicion = 0;

	int mascara_limpieza = (0xFFFFFFFF) << ((3 - tamanio_buffer) * 8);
	buffer_shifteado = (((int)buffer[0] << 16) | ((int)buffer[1]) << 8) | (int)buffer[2];
	buffer_shifteado = buffer_shifteado & mascara_limpieza;
	mascaraBase = 0x00FC0000;

	for (int corrimiento = 18; corrimiento >= 6*(3-tamanio_buffer); corrimiento -= 6){
		caracter_binario = (mascaraBase & buffer_shifteado);
		caracter = (mascaraBase & buffer_shifteado) >> corrimiento;
		mascaraBase = mascaraBase >> 6;	
		_buffer[posicion++] = BASE64[caracter];
	}
	printf("%s\n", _buffer);
}

int main(int argc, char const *argv[]){

	FILE *fp = argv[1] != NULL ? fopen(argv[1], "r") : stdin;
	char buffer[4];
	int tamanio_buffer;

	while (!feof(fp)) {
		buffer[3] = 0;
		fread(buffer, 1, (sizeof(buffer) - 1), fp);
		tamanio_buffer = strlen(buffer);
		codificar(buffer,tamanio_buffer);
	}	
}

