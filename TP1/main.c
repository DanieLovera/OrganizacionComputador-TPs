#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>

#define MAX_FUNCTIONS_TO_RUN 2
#define STDIN_PARAM_IDENTIFIER "-"
#define INVALID_RESULT 0

extern unsigned int mcd_euclides(unsigned int a, unsigned int b);
extern unsigned int mcm_euclides(unsigned int a, unsigned int b);

typedef unsigned int (*bin_operation_t) (unsigned int, unsigned int);

bool is_in_range(unsigned int value, unsigned int min, unsigned int max) {
	return min <= value && value < max;
}

unsigned int bin_operation_decorator(bin_operation_t operation, unsigned int a, 
									 unsigned int b) {
	if (!is_in_range(a, 2, INT_MAX) || !is_in_range(b, 2, INT_MAX))
		return INVALID_RESULT;
	return operation(a, b);
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
			int this_option_optind = optind ? optind : 1;
			case 'h':
				printf("helping me\n");
				break;
			case 'V':
				printf("version\n");
				break;
			case 'o':
				if (strcmp(optarg, STDIN_PARAM_IDENTIFIER) != 0)
					output_file = fopen(optarg, "w");
				break;
			case 'd':
				printf("divisor\n");
				functions[(*functions_to_run)++] = mcd_euclides;
				break;
			case 'm':
				printf("multiple\n");
				functions[(*functions_to_run)++] = mcm_euclides;
				break;
			case 0:
				printf("long option %s", argument_options[option_index].name);
				if (optarg) 
					printf(" with arg %s", optarg);
				printf("\n");
				break;
			case '?':
				// TODO: Hacer un tratado mejor de errores
				printf("error\n");
				break;
			default:
				printf("error: %c \n", opt);
				break;
		}
		option_index = 0;
	}
	return optind;
}


int main(int argc, char *argv[]) {
	bin_operation_t functions[MAX_FUNCTIONS_TO_RUN] = {
		mcd_euclides,
		mcm_euclides
	};

	int functions_to_run = 0;
	FILE* output_file = stdin;
	
	int last_index = parse_argv(argc, argv, output_file, functions, 
								&functions_to_run);

	if (!output_file) {
		fprintf(stderr, "No se pudo acceder al archivo de salida.\n");
		return -1;
	}
	
	if (!argv[last_index] || !argv[last_index + 1]) {
		fprintf(stderr, "Faltan los números.\n");
		return -1;
	}

	unsigned int a = atoi(argv[last_index]);
	unsigned int b = atoi(argv[last_index + 1]);

	if (functions_to_run == 0)
		functions_to_run = MAX_FUNCTIONS_TO_RUN;

	for (int i = 0; i < functions_to_run; i++) {
		unsigned int result = functions[i](a, b);
		if (result == INVALID_RESULT) {
			fprintf(stderr, "Número fuera de rango.\n");
			break;
		}
		fprintf(output_file, "%u\n", result);
	}

	if (output_file != stdin)
		fclose(output_file);

	return 0;
}
