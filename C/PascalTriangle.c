#include<stdio.h>

int Factorial(int n) {
	if(n < 2)
		return 1;
	//return n*Factorial(n - 1); // Recursive Solution
	int result = 1, i;
	for(i = 2; i <= n; i++)
		result *= i;
	return result;
}

void main() {
	int height = 5;
	int i = 0, j = height;
	for(i = 0; i < height; i++) {
		for(j = 0; j < height - i - 1; j++)
			printf(" ");
		for(j = 0; j <= i; j++) {
			int combinations = Factorial(i)/(Factorial(j)*Factorial(i - j));
			printf("%d ", combinations);
		}
	
		printf("\n");
	}
}
