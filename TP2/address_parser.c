#include "address_parser.h"

unsigned int address_parser_tag(unsigned int address
	, unsigned int block_size, unsigned int total_sets) {
	return address / (block_size * total_sets);
}

unsigned int address_parser_set(unsigned int address
	, unsigned int block_size, unsigned int total_sets) {
	return (address / block_size) % total_sets;
}

unsigned int address_parser_offset(unsigned int address
	, unsigned int block_size) {
	return address % block_size;
}