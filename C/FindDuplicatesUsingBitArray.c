/*You have an array with all the numbers from 0 to N - 1, where N is at most 32,000. The
array may have duplicate entries and you do not know what N is. With only 4 kilo- 
bytes of memory available, how would you print all duplicate elements in the array? */

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 35

void GetBitBytePosition(int num, int* bytePosition, int* bitNumber) {
	*bytePosition = num / 32; // we can also do num >> 5
        *bitNumber = num % 32; // we can also do num & 31
}

bool CheckIfPresent(int* bitSet, int num) {
	int bytePosition, bitNumber;
	GetBitBytePosition(num, &bytePosition, &bitNumber);

	return ((bitSet[bytePosition] & (1 << bitNumber)) != 0);
}

void SetNumber(int* bitSet, int num) {
	int bytePosition, bitNumber;
        GetBitBytePosition(num, &bytePosition, &bitNumber);

	bitSet[bytePosition] |= 1 << bitNumber;
}

void CheckDuplicates(int* array) {
/*We have 4 kilobytes of memory which means we can address up to 8 * 4 * 2^10 bits. 
Note that 32 * 2^10 bits is greater than 32000. We can create a bit vector with 32000 bits, */

	int bitSet[N/(8*sizeof(int))]; //Since int takes 4 bytes = 32 bits, so we need to divide by 32 inorder to get the actual bit size required.
	memset(bitSet, 0, N/8);
	int i;
	printf("\nDuplicates: ");
	for(i = 0; i < N; i++) {
		int num = array[i];
		if(CheckIfPresent(bitSet, num))
			printf("%d, ", num);
		else
			SetNumber(bitSet, num);
	}
	printf("\n");
}

void main() {
	int array[N], i;
	for(i = 0; i < N; i++) {
		array[i] = rand() % N;
		printf("%d, ", array[i]);
	}
	printf("\n");

	CheckDuplicates(array);
}
