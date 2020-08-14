#include<stdio.h>

double CalculatePower(double base, unsigned int exponent) {
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;
	double result = CalculatePower(base, exponent >> 1);
	result *= result;
	if((exponent & 1) == 1)
		result *= base;
	return result;

}

void main() {
	double base = 2.71;
	unsigned int exponent = 9;

	double result = CalculatePower(base, exponent);
	printf("Result is %f \n", result);
}
