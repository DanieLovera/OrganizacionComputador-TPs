#include "address_parser.h"
#include "cache.h"
#include <stdio.h>

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

int main() {
	unsigned int capacity = 32;
	unsigned int n_ways = 32;
	cache_init(32, 2, 4);
	// cache_init(8 * 1024, 4, 16);
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
	
	printf("___________________________________\n");
	// set 0 via 0
	write_byte(1, 'a');
	printf("MR: %% %d\n", get_miss_rate());
	char buff[1];
	memory_read_byte(&memory, buff, 1);

	printf("char recuperado %c\n", read_byte(1));
	printf("MR: %% %d\n", get_miss_rate());

	printf("%d\n", buff[0]);

	printf("___________________________________\n");
	// set 0 via 1
	write_byte(32, 'q');
	printf("MR: %% %d\n", get_miss_rate());

	printf("char recuperado %c\n", read_byte(32));
	printf("MR: %% %d\n", get_miss_rate());

	printf("___________________________________\n");
	printf("___________________________________\n");
	// set 0 via 0
	write_byte(16, 'l');
	printf("MR: %% %d\n", get_miss_rate());
	
	printf("char recuperado %c\n", read_byte(16));
	printf("MR: %% %d\n", get_miss_rate());
	printf("___________________________________\n");


	// printf("char recuperado %c\n", read_byte(32));
	// printf("MR: %% %d\n", get_miss_rate());
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
	return 0;
}