#include <stdio.h>
#include <stdlib.h>

extern unsigned int mcd_euclides(unsigned int a, unsigned int b);
extern unsigned int mcm_euclides(unsigned int a, unsigned int b);

int main(int argc, char *argv[]) {
	//printf("El MCD es: %u\n", mcd_euclides(1111, 1294));
	//printf("El MCM es: %u\n", mcm_euclides(1111, 1294));
	
	printf("El MCD es: %u\n", mcd_euclides(atoi(argv[1]), atoi(argv[2])));
	printf("El MCM es: %u\n", mcm_euclides(atoi(argv[1]), atoi(argv[2])));
	return 0;
}
