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


void test_02() {	
	write_byte(0, (char)123);
	write_byte(1024, (char)234);
	write_byte(2048, (char)33);
	write_byte(3072, (char)44);
	write_byte(4096, (char)55);

	read_byte(0);
	read_byte(1024);
	read_byte(2048);
	read_byte(3072);
	read_byte(4096);
}

void test_basic_small() { // Usar memoria de 64 bytes
	cache_init(32, 2, 4);
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
	
	// <>
	// Código para verificar si se actualiza la memoria caché y la memoria queda
	// desactualizada
	printf("___________________________________\n");
	// set 0 via 0
	write_byte(1, 'a');
	printf("MR: %% %d\n", get_miss_rate());
	char buff[1];
	memory_read_byte(&memory, buff, 1);

	printf("char recuperado %c\n", read_byte(1));
	printf("MR: %% %d\n", get_miss_rate());

	printf("%d\n", buff[0]);
	// </>

	printf("___________________________________\n");
	// set 0 via 1
	write_byte(32, 'q');
	printf("MR: %% %d\n", get_miss_rate());

	printf("char recuperado %c\n", read_byte(32));
	printf("MR: %% %d\n", get_miss_rate());

	printf("___________________________________\n");
	
	// set 0 via 1
	write_byte(16, 'l');
	printf("MR: %% %d\n", get_miss_rate());
	
	printf("char recuperado %c\n", read_byte(16));
	printf("MR: %% %d\n", get_miss_rate());
	
	printf("___________________________________\n");
	
	// set 0 via 1

	printf("char recuperado %c\n", read_byte(32));
	printf("MR: %% %d\n", get_miss_rate());

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
}

int main() {
	unsigned int capacity = 8 * 1024;
	unsigned int n_ways = 4;
	unsigned int block_size = 16;
	init();
	cache_init(capacity, n_ways, block_size);

	// test_01();
	// printf("MR: %% %d\n", get_miss_rate());
	// printf("%u\n", address_parser_set(0, block_size, 128));
	// printf("%u\n", address_parser_set(1024, block_size, 128));
	// printf("%u\n", address_parser_set(2048, block_size, 128));
	// printf("%u\n", address_parser_set(3072, block_size, 128));
	// printf("%u\n", address_parser_set(4096, block_size, 128));


	test_02();
	printf("MR: %% %d\n", get_miss_rate());

	cache_uninit();

	return 0;
}
