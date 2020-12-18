#ifndef _ADDRESS_PARSER_H_
#define _ADDRESS_PARSER_H_

unsigned int address_parser_tag(unsigned int address
	, unsigned int block_size, unsigned int total_sets);
unsigned int address_parser_set(unsigned int address
	, unsigned int block_size, unsigned int total_sets);
unsigned int address_parser_offset(unsigned int address
	, unsigned int block_size);

#endif