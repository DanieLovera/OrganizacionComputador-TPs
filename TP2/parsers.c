#include "parsers.h"
#include "strutil.h"
#include "cache.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#define COMMAND_DELIMITER ' '

static bool init_wrapper(char *args[]);
static bool write_wrapper(char *args[]);
static bool read_wrapper(char *args[]);
static bool get_miss_rate_wrapper(char *args[]);
static bool command_not_found(char *args[]);
static int vector_look_up(char *vector[], char *search_value, int vector_len);
static void show_usage();
static void show_version();
static bool is_arg_equal_short_long(char *arg, char *short_form, 
									char *long_form);
static char* safe_get(char *vector[], int index, int vector_len, 
					  char *long_form);
static bool is_a_number(char* num);
static int safe_get_int(char *vector[], int index, int vector_len, 
						int long_form);

// ---------------- CommandParser ----------------

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

static bool init_wrapper(char *args[]) {
	init();
	fprintf(stdout, "Se inicia la caché\n");
	return true;
}

static bool write_wrapper(char *args[]) {
	if (!args[1] || !args[2]) return false;
	int mem_direction = atoi(args[1]);
	char data = (char)atoi(args[2]);
	write_byte(mem_direction, data);
	fprintf(stdout, "Escribe %c en la dirección %d\n", data, mem_direction);
	return true;
}

static bool read_wrapper(char *args[]) {
	if (!args[1]) return false;
	int mem_direction = atoi(args[1]);
	char resultado = read_byte(mem_direction);
	fprintf(stdout, "Leo de la dirección %d y obtengo %c\n", mem_direction, 
			resultado);
	return true;
}

static bool get_miss_rate_wrapper(char *args[]) {
	fprintf(stdout, "MR: %%%d\n" , get_miss_rate());
	return true;
}

static bool command_not_found(char *args[]) {
	fprintf(stderr, "Archivo con formato inválido.\n");
	return false;
}


static int vector_look_up(char *vector[], char *search_value, int vector_len) {
	for (int i = 0; i < vector_len; i++) {
		if (strncmp(search_value, vector[i], 
					strlen(vector[i])) == 0) {
			return i;
		}
	}
	return -1;
}

// ---------------- ArgParser ----------------

void argparser_init(argparser_t *self) {
	self->capacity = -1;
	self->n_ways = -1;
	self->block_size = -1;
	self->output = NULL;
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

static void show_usage() {
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
			"	-bs, --blocksize	Tamaño del bloque en bytes.\n"
			"Examples:\n"
			"	tp2 -w 4 -cs 8 -bs 16 prueba1.mem\n");
}

static void show_version() {
	fprintf(stdout, "Version 1.0\n");
}


static bool is_arg_equal_short_long(char *arg, char *short_form, 
									char *long_form) {
	return strcmp(arg, short_form) == 0 || strcmp(arg, long_form) == 0;
}

static char* safe_get(char *vector[], int index, int vector_len, 
					  char *default_value) {
	if (index < 0 || index >= vector_len) 
		return default_value;
	return vector[index];
}

static bool is_a_number(char* num) {
	if (num[0] != '-' && !isdigit(num[0])) 
		return false;

	size_t len_number = strlen(num);
	for (size_t i = 1; i < len_number; i++){
		if (!isdigit(num[i])) 
			return false;
	}
	return true;
}

static int safe_get_int(char *vector[], int index, int vector_len, 
						int default_value) {
	if (index < 0 || index >= vector_len || !is_a_number(vector[index]))
		return default_value;
	return atoi(vector[index]);
}
