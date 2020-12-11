#ifndef _MEMORY_H_
#define _MEMORY_H_

#define CAPACITY 64 //En bytes

typedef struct memory {
	char data[CAPACITY];
} memory_t;

void memory_init(memory_t *self);
void memory_uninit(memory_t *self);
void memory_write_byte(memory_t *self
		, char data, int byte_address);
void memory_read_byte(memory_t *self
		, char *data_buffer, int byte_address);
void memory_write(memory_t *self, char *data
		, int address, unsigned int data_size); 
void memory_read(memory_t *self, char *data_buffer
		, int address, unsigned int data_size);

#endif 
