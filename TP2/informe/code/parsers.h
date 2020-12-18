#ifndef __PARSERS_H__
#define __PARSERS_H__

#define AVAILABLE_OPTIONS 4
#include <stdbool.h>

typedef bool (*command_f_t)(char*[]);

typedef struct {
	command_f_t selected_command;
	char *command_names[AVAILABLE_OPTIONS];
	command_f_t commands[AVAILABLE_OPTIONS];
} command_t;


void command_init(command_t *self);

bool command_parse_line(command_t *self, char *line);

typedef struct {
	int capacity;
	int n_ways;
	int block_size;
	char *output;
} argparser_t;

void argparser_init(argparser_t *self);

void argparser_parse(argparser_t *self, int argc, char *argv[]);

bool argparser_is_command_valid(argparser_t *self);



#endif
