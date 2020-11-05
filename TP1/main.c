#include <stdio.h>
extern unsigned int mcd_euclides(unsigned int a, unsigned int b);
extern unsigned int mcm_euclides(unsigned int a, unsigned int b);

int main() {
	printf("El MCD es: %u\n", mcd_euclides(1111, 1294));
	printf("El MCM es: %u\n", mcm_euclides(1111, 1294));
	return 0;
}
