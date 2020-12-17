#define _POSIX_C_SOURCE 200809L 
#include "strutil.h"
#include "address_parser.h"
#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void test_01() {	
	write_byte(0, (char)255);
	write_byte(16384, (char)254);
	write_byte(32768, (char)248);
	write_byte(49152, (char)96);

	read_byte(0);
	read_byte(16384);
	read_byte(32768);
	read_byte(49152);
}


void test_02() {	
	write_byte(0, (char)123);
	write_byte(1024, (char)234);
	write_byte(2048, (char)33);
	write_byte(3072, (char)44);
	write_byte(4096, (char)55);

	read_byte(0);
	read_byte(1024);
	read_byte(2048);
	read_byte(3072);
	read_byte(4096);
}

void test_basic_small() { // Usar memoria de 64 bytes
	cache_init(32, 2, 4);
	printf("___________________________________\n");
	// printf("%u\n", find_set(1));
	// printf("%u\n", find_set(4));
	// printf("%u\n", find_set(63));

	// printf("%d\n", find_lru(0));
	// printf("%u\n", is_dirty(1, 2));

	printf("___________________________________\n");
	// set 0 via 0
	write_byte(0, 'd'); 
	printf("MR: %% %d\n", get_miss_rate());

	printf("char recuperado %c\n", read_byte(0));
	printf("MR: %% %d\n", get_miss_rate());
	
	// <>
	// Código para verificar si se actualiza la memoria caché y la memoria queda
	// desactualizada
	printf("___________________________________\n");
	// set 0 via 0
	write_byte(1, 'a');
	printf("MR: %% %d\n", get_miss_rate());
	//char buff[1];
	//memory_read_byte(&memory, buff, 1);

	printf("char recuperado %c\n", read_byte(1));
	printf("MR: %% %d\n", get_miss_rate());

	//printf("%d\n", buff[0]);
	// </>

	printf("___________________________________\n");
	// set 0 via 1
	write_byte(32, 'q');
	printf("MR: %% %d\n", get_miss_rate());

	printf("char recuperado %c\n", read_byte(32));
	printf("MR: %% %d\n", get_miss_rate());

	printf("___________________________________\n");
	
	// set 0 via 1
	write_byte(16, 'l');
	printf("MR: %% %d\n", get_miss_rate());
	
	printf("char recuperado %c\n", read_byte(16));
	printf("MR: %% %d\n", get_miss_rate());
	
	printf("___________________________________\n");
	
	// set 0 via 1

	printf("char recuperado %c\n", read_byte(32));
	printf("MR: %% %d\n", get_miss_rate());

	// printf("___________________________________\n");
	
	// char buff[1];
	// memory_read_byte(&memory, buff, 1);
	// printf("char recuperado a == %c\n", buff[0]);

	// printf("___________________________________\n");
	// // set 0 via 0
	// write_byte(0, 'd');
	// printf("MR: %% %d\n", get_miss_rate());
	
	// printf("___________________________________\n");
	// printf("char recuperado %c\n", read_byte(16));
	// printf("MR: %% %d\n", get_miss_rate());
	// test_01();
	cache_uninit();
}

	// test_01();
	// printf("MR: %% %d\n", get_miss_rate());
	// printf("%u\n", address_parser_set(0, block_size, 128));
	// printf("%u\n", address_parser_set(1024, block_size, 128));
	// printf("%u\n", address_parser_set(2048, block_size, 128));
	// printf("%u\n", address_parser_set(3072, block_size, 128));
	// printf("%u\n", address_parser_set(4096, block_size, 128));

//	test_02();
//	printf("MR: %% %d\n", get_miss_rate());

#define AVAILABLE_OPTIONS 4
#define COMMAND_DELIMITER ' '

typedef bool (*command_f_t)(char*[]);

typedef struct {
	command_f_t selected_command;
	char *command_names[AVAILABLE_OPTIONS];
	command_f_t commands[AVAILABLE_OPTIONS];
} command_t;

bool init_wrapper(char *args[]) {
	init();
	return true;
}

bool write_wrapper(char *args[]) {
	if (!args[1] || !args[2]) return false;
	int mem_direction = atoi(args[1]);
	char data = (char)atoi(args[2]);
	write_byte(mem_direction, data);
	return true;
}

bool read_wrapper(char *args[]) {
	if (!args[1]) return false;
	int mem_direction = atoi(args[1]);
	read_byte(mem_direction);
	return true;
}

bool get_miss_rate_wrapper(char *args[]) {
	fprintf(stdout, "MR: %%%d\n" , get_miss_rate());
	return true;
}

bool command_not_found(char *args[]) {
	fprintf(stderr, "Archivo con formato inválido.\n");
	return false;
}

void command_init(command_t *self) {
	self->command_names[0] = "init";
	self->command_names[1] = "R";
	self->command_names[2] = "W";
	self->command_names[3] = "MR";
	
	self->commands[0] = init_wrapper;
	self->commands[1] = read_wrapper;
	self->commands[2] = write_wrapper;
	self->commands[3] = get_miss_rate_wrapper;
}

int vector_look_up(char *vector[], char *search_value, int vector_len) {
	for (int i = 0; i < vector_len; i++) {
		if (strncmp(search_value, vector[i], 
					strlen(vector[i])) == 0) {
			return i;
		}
	}
	return -1;
}

bool command_parse_line(command_t *self, char *line) {
	char **splitted_line = split(line, COMMAND_DELIMITER);	
	char *str_command = splitted_line[0];
	int i_command = vector_look_up(self->command_names, str_command, 
								   AVAILABLE_OPTIONS);
	if (i_command < 0)
		self->selected_command = command_not_found;
	else 
		self->selected_command = self->commands[i_command];
	bool result = self->selected_command(splitted_line);
	free_strv(splitted_line);
	return result;
}


typedef struct {
	int capacity;
	int n_ways;
	int block_size;
	char *output;
} argparser_t;

void show_usage() {
	fprintf(stdout, 
		    "Usage:\n"
		    "	tp2 -h\n"
		    "	tp2 -V\n"
		    "	tp2 options archivo\n"
		    "Options:\n"
		    "	-h, --help 			Imprime ayuda.\n"
		    "	-V, --version 		Versión del programa.\n"
		    "	-o, --output 		Archivo de salida.\n"
		    "	-w, --ways			Cantidad de vías.\n"
		    "	-cs --cachesize 	Tamaño del caché en kilobytes.\n"
		    "	-bs, --blocksize	Tamaño del bloque en bytes.\n");
}

void show_version() {
	fprintf(stdout, "Version 1.0\n");
}

void argparser_init(argparser_t *self) {
	self->capacity = -1;
	self->n_ways = -1;
	self->block_size = -1;
	self->output = NULL;
}

bool is_arg_equal_short_long(char *arg, char *short_form, char *long_form) {
	return strcmp(arg, short_form) == 0 || strcmp(arg, long_form) == 0;
}

char* safe_get(char *vector[], int index, int vector_len, char *default_value) {
	if (index < 0 || index >= vector_len) 
		return default_value;
	return vector[index];
}

bool is_a_number(char* num) {
	if (num[0] != '-' && !isdigit(num[0])) 
		return false;

	size_t len_number = strlen(num);
	for (size_t i = 1; i < len_number; i++){
		if (!isdigit(num[i])) 
			return false;
	}
	return true;
}

int safe_get_int(char *vector[], int index, int vector_len, int default_value) {
	if (index < 0 || index >= vector_len || !is_a_number(vector[index]))
		return default_value;
	return atoi(vector[index]);
}

void argparser_parse(argparser_t *self, int argc, char *argv[]) {
	int last_index = 0;
	for (int i = 1; i < argc; i++) {
		char *arg = argv[i];
		if (is_arg_equal_short_long(arg, "-h", "--help")) {
			show_usage();
			exit(EXIT_SUCCESS);
		} else if (is_arg_equal_short_long(arg, "-V", "--version")) {
			show_version();
			exit(EXIT_SUCCESS);
		} else if (is_arg_equal_short_long(arg, "-o", "--output")) {
			self->output = safe_get(argv, ++i, argc, "");
			last_index = i;
		} else if (is_arg_equal_short_long(arg, "-w", "--ways")) {
			self->n_ways = safe_get_int(argv, ++i, argc, -1);
			last_index = i;
		} else if (is_arg_equal_short_long(arg, "-cs", "--cachesize")) {
			self->capacity = safe_get_int(argv, ++i, argc, -1);
			last_index = i;
		} else if (is_arg_equal_short_long(arg, "-bs", "--blocksize")) {
			self->block_size = safe_get_int(argv, ++i, argc, -1);
			last_index = i;
		}
	}
	if (!self->output && last_index < argc - 1) {
		self->output = argv[++last_index];
	}
}

bool argparser_is_command_valid(argparser_t *self) {
	return (self->output != NULL) && (self->n_ways > 0) && 
		   (self->capacity > 0) && (self->block_size > 0);
}

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
	
	// unsigned int capacity = 4 * 1024;
	// unsigned int n_ways = 4;
	// unsigned int block_size = 32;

	int capacity = argparser.capacity;
	int n_ways = argparser.n_ways;
	int block_size = argparser.block_size;
	printf("%d %d %d \n", capacity, n_ways, block_size);
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
