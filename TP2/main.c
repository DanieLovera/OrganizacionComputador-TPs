#define _POSIX_C_SOURCE 200809L 
#include "address_parser.h"
#include "cache.h"
#include "parsers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	argparser_t argparser;
	argparser_init(&argparser);
	argparser_parse(&argparser, argc, argv);
	if (!argparser_is_command_valid(&argparser)) {
		fprintf(stderr, "Error en los argumentos\n");
		exit(EXIT_FAILURE);
	}

	char *output_file = argparser.output;
	FILE *file = fopen(output_file, "r");
	if (!file) {
		fprintf(stderr, "No se pudo abrir el archivo %s\n", output_file);
		exit(EXIT_FAILURE);
	}
	size_t num_bytes = 0;
	char* line = NULL;
	
	int capacity = argparser.capacity * 1024;
	int n_ways = argparser.n_ways;
	int block_size = argparser.block_size;

	cache_init(capacity, n_ways, block_size);	
	command_t command;
	command_init(&command);
	while(getline(&line, &num_bytes, file) != -1) {
		if (!command_parse_line(&command, line)) 
			break;
	}

	free(line);
	fclose(file);
	cache_uninit();
	
	return 0;
}
