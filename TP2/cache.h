#ifndef _CACHE_H_
#define _CACHE_H_
#include <stdbool.h>
#include "memory.h"

typedef struct set set_t;
typedef struct block block_t;

typedef struct cache {
	unsigned int capacity;
	unsigned int ways_number;
	unsigned int block_size;
	set_t *sets;
	unsigned int misses;
	unsigned int hits;
} cache_t;

struct set {
	block_t *blocks;
};

struct block {
	char *data;
	int lru_counter;
	unsigned int tag;
	bool dirty;
	bool valid;
	bool last_used;
};

void cache_init(unsigned int capacity, unsigned int ways_number, unsigned int block_size);
void cache_uninit();
void init();
unsigned int find_set(int address);
unsigned int find_lru(int setnum);
unsigned int is_dirty(int way, int setnum);
void read_block(int blocknum);
void write_block(int way, int setnum);
char read_byte(int address);
void write_byte(int address, char value);
int get_miss_rate();

#endif
