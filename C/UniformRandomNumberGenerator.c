//Given a Random Number Generator which unbiasedly produces either 0 Or 1.
// Devise a new Random Number Generator which give a random number between 2 numbers.

#include<stdio.h>

int GetRandom(int a, int b) {
	int numberOfOutcomes = b - a + 1;
	int result, i;
	do {
		result = 0;
		for(i = 0; (1 << i) < numberOfOutcomes; i++)
			result = (result << 1) | (rand() % 2);
		
	} while(result >= numberOfOutcomes);

	return result + a;
}

void main() {
	int a = 5;
	int b = 15;
	int i;
	for(i = a; i < b; i++)
		printf("%d\n",GetRandom(a, b));
}
