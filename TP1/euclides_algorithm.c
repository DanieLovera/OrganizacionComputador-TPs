#include "euclides_algorithm.h"

unsigned int mcd_euclides(unsigned int a, unsigned int b) {
	unsigned int r = 0;
	
	if (b == 0) {
		return a;
	}
	r = (a % b);
	return mcd_euclides(b, r);
}

unsigned int mcm_euclides(unsigned int a, unsigned int b) {
	unsigned int mcd = mcd_euclides(a, b);
	unsigned int a_x_b = (a * b);
	return (a_x_b / mcd);
}
