/*Find all the prime number between 1 and N*/

#include<stdio.h>
#include<string.h>
#include<math.h>

#define N 50

int GetNextPrimeNumber(int* array, int primeNumber, int length) {
	while(primeNumber < length)
		if(array[primeNumber] != 1)
			return primeNumber;
		else
			primeNumber++;
}

void main() {
	int n = N;

	int array[n+1];

	memset(array, 0, (n+1)*sizeof(int));	// Initialize all the elements of array to 0.
	
	int j,primeNumber;
	for(primeNumber = 2; primeNumber <= sqrt(n); ) {
		for (j = primeNumber*primeNumber; j < n + 1; j += primeNumber) {
			array[j] = 1;	//In 1st iteration we are filling the multiples of 2,
					//In 2nd iteration we are filling the multiples of 3, and so on and so forth.	
		}
		
		primeNumber = GetNextPrimeNumber(array, primeNumber + 1, n + 1);
	}

	int i = 1; // We should start with index 1 cause index 0 will have 0 which is not prime.
	printf("Prime Numbers between 1 and %d are : \n", n);
	int count = 0;
	while(i < n+1) {
		if(array[i] == 0) {
			printf("%d| ", i);
			count++;
		}

		i++;
	}	
	
	printf("\nTotal Number of Primes are %d\n", count);
}
