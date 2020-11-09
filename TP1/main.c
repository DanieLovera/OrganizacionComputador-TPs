#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>

#define MAX_FUNCTIONS_TO_RUN 2
#define STDIN_PARAM_IDENTIFIER "-"
#define INVALID_RESULT 0
#define MIN_VALUE_INPUT 2
#define MAX_VALUE_INPUT INT_MAX
#define CORRECT_INPUT 0
#define ALPHA_ERROR 1
#define NEGATIVE_ERROR 2

extern unsigned int mcd_euclides(unsigned int a, unsigned int b);
extern unsigned int mcm_euclides(unsigned int a, unsigned int b);

typedef unsigned int (*bin_operation_t) (unsigned int, unsigned int);

bool is_in_range(unsigned int value, unsigned int min, unsigned int max) {
	return min <= value && value < max;
}

int is_a_number(char* num){
	if (num[0] != '-' && !isdigit(num[0])) return ALPHA_ERROR;

	if (num[0] == '-' || isdigit(num[0])){
		for (size_t i = 1; i < strlen(num); i++){
			if (!isdigit(num[i])) return ALPHA_ERROR;
		}
		if (num[0] == '-') return NEGATIVE_ERROR;

		return CORRECT_INPUT;
	}

	return ALPHA_ERROR;
}

bool correct_input(char* num1, char* num2){
	int result_1 = is_a_number(num1);
	int result_2 = is_a_number(num2);
	if (result_1 + result_2 == CORRECT_INPUT) return true;

	if (result_1 == ALPHA_ERROR || result_2 == ALPHA_ERROR){
		fprintf(stderr, "Error: deben ingresarse numeros no cadenas de texto\n");
		return false;
	}

	fprintf(stderr, "Error: Los numeros ingresados deben ser positivos y estar en el rango [%d, %d]\n", MIN_VALUE_INPUT,
		MAX_VALUE_INPUT);

}

unsigned int bin_operation_decorator(bin_operation_t operation, unsigned int a, 
									 unsigned int b) {
	if (!is_in_range(a, MIN_VALUE_INPUT, MAX_VALUE_INPUT) || 
		!is_in_range(b, MIN_VALUE_INPUT, MAX_VALUE_INPUT))
		return INVALID_RESULT;
	return operation(a, b);
}

void show_usage() {
	printf("Usage:\n"
		   "	common -h\n"
		   "	common -V\n"
		   "	common [options] M N\n"
		   "Options:\n"
		   "	-h, --help Prints usage information.\n"
		   "	-V, --version Prints version information.\n"
		   "	-o, --output Path to output file.\n"
		   "	-d --divisor Just the divisor\n"
		   "	-m --multiple Just the multiple\n");
}

void show_version() {
	printf("Version 1.0\n");
}

int parse_argv(int argc, char *argv[], FILE* output_file, 
			   bin_operation_t functions[], int *functions_to_run) {
	opterr = 0; // getopt suprime los mensajes de error
	static struct option argument_options[] = {
		{"help", no_argument, 0, 'h'},
		{"version", no_argument, 0, 'V'},
		{"output", required_argument, 0, 'o'},
		{"divisor", no_argument, 0, 'd'},
		{"multiple", no_argument, 0, 'm'},
		{0, 0, 0, 0} // Lo pide getopt
	};

	int opt;
	int option_index = 0;
	while ((opt = getopt_long(argc, argv, "hVo:dm", argument_options, 
														&option_index)) != -1) {
		switch (opt) {
		case 'h':
			show_usage();
			exit(EXIT_SUCCESS);
		case 'V':
			show_version();
			exit(EXIT_SUCCESS);
		case 'o':
			if (strcmp(optarg, STDIN_PARAM_IDENTIFIER) != 0) {
				output_file = fopen(optarg, "w");
				if (!output_file) {
					fprintf(stderr, "No se pudo abrir el archivo %s\n", optarg);
					exit(EXIT_FAILURE);
				}
			}
			break;
		case 'd':
			functions[(*functions_to_run)++] = mcd_euclides;
			break;
		case 'm':
			functions[(*functions_to_run)++] = mcm_euclides;
			break;
		case 0:
			// TODO: Se supone que todos los valores están contemplados en los 
			// case anteriores.
			printf("long option %s", argument_options[option_index].name);
			if (optarg) 
				printf(" with arg %s", optarg);
			printf("\n");
			break;
		case '?':
			// TODO: Hacer un tratado mejor de errores
			show_usage();
			exit(EXIT_FAILURE);
		default:
			show_usage();
			exit(EXIT_FAILURE);
		}
		option_index = 0;
	}
	return optind;
}


int main(int argc, char *argv[]) {
	FILE* output_file = stdout;
	bin_operation_t functions[] = {
		mcd_euclides,
		mcm_euclides
	};
	int functions_to_run = 0;
	
	int last_index = parse_argv(argc, argv, output_file, functions, 
								&functions_to_run);

	if (!output_file) {
		fprintf(stderr, "No se pudo acceder al archivo de salida.\n");
		exit(EXIT_FAILURE);
	}
	
	if (!argv[last_index] || !argv[last_index + 1]) {
		fprintf(stderr, "Faltan los números.\n");
		show_usage();
		exit(EXIT_FAILURE);
	}

	if(!correct_input(argv[last_index], argv[last_index + 1])) exit(EXIT_FAILURE);

	unsigned int a = atoi(argv[last_index]);
	unsigned int b = atoi(argv[last_index + 1]);

	if (functions_to_run == 0)
		functions_to_run = MAX_FUNCTIONS_TO_RUN;

	for (int i = 0; i < functions_to_run; i++) {
		unsigned int result = bin_operation_decorator(functions[i], a, b);
		if (result == INVALID_RESULT) {
			fprintf(stderr, "Número fuera de rango [%d, %d).\n", 
											MIN_VALUE_INPUT, MAX_VALUE_INPUT);
			break;
		}
		fprintf(output_file, "%u\n", result);
	}

	if (output_file != stdout)
		fclose(output_file);

	return EXIT_SUCCESS;
}
