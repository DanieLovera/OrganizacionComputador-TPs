#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#define _POSIX_C_SOURCE 200809L //para incluir getline
char* BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int mascaraBase = 0x00FC0000;


void printHelp();
void decode(FILE* inputFile, FILE* outputFile);
void code(FILE* inputFile, FILE* outputFile);
int combineBytes(char* block, size_t readBytes, bool code);
char* codification(int binaryCode, size_t readBytes);
char* decodification(int binaryCode, size_t readBytes);
int findPosition(char caracter);
void removeEquals(char* buffer, size_t* readBytes);
void resetBuffer(char* buffer);



int main(int argc, char const *argv[]){
	bool code = true; //flag para saber que operacion realizar
	FILE* inputFile = stdin;
	FILE* outputFile = stdout;
	char* (*func)(int, size_t) = codification;

	for (size_t i = 1; i < argc; i++){
		if (!strcmp(argv[i], "-h")) {
			printHelp();
			break;
		}

		else if (!strcmp(argv[i], "-V")){
			fprintf(stdout, "Version 1.0.0\n");
			break;
		}

		else if (!strcmp(argv[i], "-d")){
			code = false;
			func = decodification;
		}

		else if (!strcmp(argv[i], "-i")){
			inputFile = fopen(argv[i + 1], "r");

			if(!inputFile){
					fprintf(stderr, "Error: Cannot open/find the specified input file");
			}
		}

		else if (!strcmp(argv[i], "-o")){
			outputFile = fopen(argv[i + 1], "r");

			if(!outputFile){
					fprintf(stderr, "Error: Cannot open/find the specified input file");
			}
		}
	}

	int bufferSize = (code) ? 4 : 5; // ambos estan +1 para incluir el \0
	char buffer[bufferSize];
	buffer[bufferSize - 1] = '\0';
	size_t readBytes = fread(buffer, 1, sizeof(buffer) - 1, inputFile);

	while(!feof(inputFile) || readBytes != 0){
		
		/*if (feof(inputFile)){ //DECIDIR QUE HACER CON ESTO
			buffer[readBytes--] = '\0';
		}*/

		if (!code && strstr(buffer, "=")){
			removeEquals(buffer, &readBytes);
		}

		if (!code && strstr(buffer, "\n")) break; //decidir despues, el texto codificado no puede tener \n, no quiere decir que no se pueda formar

		int resultado = combineBytes(buffer, readBytes, code);
		
		if (resultado < 0){
			return 1;
		}
		char* result = func(resultado, readBytes);
		printf("%s", result); //usar fwrite despues
		free(result);
		resetBuffer(buffer);
		readBytes = fread(buffer, 1, sizeof(buffer) - 1, inputFile); //queda con basura
	}
	printf("\n");
	return 0;
}



void printHelp(){
	fprintf(stdout, "Usage:\n\ttp0 -h\n\ttp0 -V\n\ttp0 [options]\n");
	fprintf(stdout, "Options:\n\t-V, --version \tPrint version and quit.\n\t-h, --help \tPrint this information.\n\t-o, --output \tPath to output file.\n\t-i, --input \tPath to input file.\n\t-d, --decode \tDecode a base64-encoded file.\n");
	fprintf(stdout, "Examples: \n\ttp0 -i input.txt -o output.txt\n");

}

int combineBytes(char* block, size_t readBytes, bool code){
	int resultado = (0x00000000);
	int SHIFTS = 24;
	int mult = (code) ? 8 : 6;
	for (int i = 0; i < readBytes; i++){
		int shiftRight = SHIFTS - (i + 1) * mult;
		int toShift = (code) ? (int)block[i] : findPosition(block[i]);
		if (toShift < 0){
			fprintf(stderr, "Error: El caracter %c no se encuentra en base 64\n", block[i]);
			return -1;
		}
		resultado |= toShift << shiftRight;
	}
	return resultado;
}


char* codification(int binaryCode, size_t readBytes){//podria recibir un booleano code = true decode = false
	int shiftsLeft[] = {8, 14, 20, 26};
	int shiftRight = 26; //ojo que cambia segun codificas o decodificas 24 si decodificas
	char* code = malloc(5);
	code[0] = '=';
	code[1] = '=';
	code[2] = '=';
	code[3] = '=';
	code[4] = '\0';
	size_t posCode = 0;
	for (size_t i = 0; i < readBytes + 1; i++){ //1 byte -> 2 iteraciones; 2 byte -> 3 iteraciones; 3 byte -> 4 iteraciones
		int binaryCodeAux = binaryCode; //para guardar el binario original
		binaryCodeAux = binaryCodeAux << shiftsLeft[i];
		binaryCodeAux = (int)((unsigned) binaryCodeAux >> shiftRight);
		code[posCode++] = BASE64[binaryCodeAux];
	}
	return code;
}

char* decodification(int binaryCode, size_t readBytes){
	int shiftsLeft[] = {8, 16, 24};
	int shiftRight = 24; 
	char* code = malloc(readBytes);
	code[readBytes - 1] = '\0';

	size_t posCode = 0;
	for (size_t i = 0; i < readBytes - 1; i++){ //1 byte -> 2 iteraciones; 2 byte -> 3 iteraciones; 3 byte -> 4 iteraciones
		int binaryCodeAux = binaryCode; //para guardar el binario original
		binaryCodeAux = binaryCodeAux << shiftsLeft[i];
		binaryCodeAux = (int)((unsigned) binaryCodeAux >> shiftRight);
		code[posCode++] = (char) binaryCodeAux;
	}
	return code;
}

int findPosition(char caracter){
	for (int i = 0; i < strlen(BASE64); i++){
		if (caracter == BASE64[i]) return i;
	}
	return -1;
}

void removeEquals(char* buffer, size_t* readBytes){
	for (size_t i = 0; i < strlen(buffer); i++){
		if (buffer[i] == '=') *readBytes -= 1;
	}
}

void resetBuffer(char* buffer){
	size_t pos = 0;
	while(buffer[pos] != '\0') buffer[pos++] = '\0';
}


/*har* codification(int binaryCode, size_t readBytes, bool code){//podria recibir un booleano code = true decode = false
	if (code){
		int shiftsLeft[] = {8, 14, 20, 26};
		int shiftRight = 26; //ojo que cambia segun codificas o decodificas 24 si decodificas
		size_t iterations = readBytes + 1;
		char* code = malloc(5);
		code[0] = '=';
		code[1] = '=';
		code[2] = '=';
		code[3] = '=';
		code[4] = '\0';
	}
	else{
		int shiftsLeft[] = {8, 16, 24};
		int shiftRight = 24; 
		size_t iterations = readBytes - 1;
		char* code = malloc(readBytes);
		code[readBytes - 1] = '\0';
	}

	size_t posCode = 0;
	for (size_t i = 0; i < iterations; i++){ //1 byte -> 2 iteraciones; 2 byte -> 3 iteraciones; 3 byte -> 4 iteraciones
		int binaryCodeAux = binaryCode; //para guardar el binario original
		binaryCodeAux = binaryCodeAux << shiftsLeft[i];
		binaryCodeAux = (int)((unsigned) binaryCodeAux >> shiftRight);
		//code[posCode++] = (code) ? BASE64[binaryCodeAux] : (char) binaryCodeAux; //si esta en code uso la cte BASE64, sino es el ascii comun
		if (code){
			code[posCode++] = BASE64[binaryCodeAux];
		}
		else{
			code[posCode++] = (char) binaryCodeAux;
		}
	}
	return code;
}*/