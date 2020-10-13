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
	printf("%s", _buffer);
}

int index_string(const char* string, char c) {
	int index = 0;
	char result;
	while ((result = string[index++]) != '\0') {
		if (result == c) 
			return index;
	}
	return -1;
}

#define TAMANIO_BUFFER_RESULTADO 4

void decodificar_bloque(char buffer[]) {
	// char _buffer[5] = "====";
	// char buffer[3] <- parametro
	int indexes[TAMANIO_BUFFER_RESULTADO];
	for (int i = 0; i < TAMANIO_BUFFER_RESULTADO; i++) {
		indexes[i] = index_string(BASE64, buffer[i]) - 1;
		printf("%c\n", BASE64[indexes[i]]);
	}
	// int mascaraBase;
	// int caracter_binario;
	// char caracter;
	// int posicion = 0;
    // mano
	// m: 38
	// a: 26
	// n: 39
	// o: 40
	// 
	// int mascara_limpieza = (0x00000000);
	// << ((3 - tamanio_buffer) * 8);
	// buffer_shifteado = buffer_shifteado | mascara_limpieza;

	int bits_juntos = ((int) indexes[0] << (6 * 3)) | 
					   ((int) indexes[1] << (6 * 2)) | 
					   ((int) indexes[2] << (6 * 1)) | 
					   ((int) indexes[3]);

	char result[TAMANIO_BUFFER_RESULTADO];

	result[0] = (bits_juntos >> 24) & 0xFF;
	result[1] = (bits_juntos >> 16) & 0xFF;
	result[2] = (bits_juntos >>  8) & 0xFF;
	result[3] = (bits_juntos >>  0) & 0xFF;
}

void decodificar(char buffer[], int tamanio_buffer) {

	decodificar_bloque(buffer);
}

int main(int argc, char const *argv[]) {
	/*
	char buffer[] = "TWFu";
	int len = 4;

	decodificar(buffer, len);

	return 0;
	*/

	FILE *fp = argv[1] != NULL ? fopen(argv[1], "r") : stdin;
	char buffer[4];
	int tamanio_buffer;
	bool keep_running = true;
	while (keep_running) {
		char c;
		char buffer[4];
		memset(buffer, 0, 4);
		int index = 0;
		while ((c = fgetc(fp)) != EOF) {    
			buffer[index++] = c;
			if (index >= 3) 
				break;
		}
		keep_running = c != EOF;
		codificar(buffer, index);
	}
	printf("\n");
}
