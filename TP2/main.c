#include "cache.h"

int main() {
	cache_init(32,2,4);
	cache_uninit();

	return 0;
}