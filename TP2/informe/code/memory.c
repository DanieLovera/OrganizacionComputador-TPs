#include "memory.h"
#include <string.h>
#include <stdio.h>

void memory_init(memory_t *self) {
	memset(self->data, 0, sizeof(self->data));
}

void memory_uninit(memory_t *self) {
	
}

void memory_write_byte(memory_t *self, char data,
		int address) {
	self->data[address] = data;
}

void memory_read_byte(memory_t *self, char *data_buffer,
		int address) {
	*data_buffer = self->data[address];
}

void memory_write(memory_t *self, char *data
		, int address, unsigned int data_size) {
	for(int index = 0; index < data_size; index++) {
		memory_write_byte(self, data[index], address++);
	}
}

void memory_read(memory_t *self, char *data_buffer
		, int address, unsigned int data_size) {
	for(int index = 0; index < data_size; index++) {
		memory_read_byte(self, (data_buffer + index), address++);
	}
}