#include<stdio.h>
#include<malloc.h>

#define SIZE 10

void main() {
	int array[SIZE] = {0,8,4,12,2,10,6,14,1,9};
	int longestLengthAtIndex[SIZE];
	int previousIndexOf[SIZE];
	int i = 0, j, maxLength = 1;
	while(i < SIZE) {
		longestLengthAtIndex[i] = 1;
		previousIndexOf[i++] = -1;
	}

	for(i = 1; i < SIZE; i++) { // Imp Step
		for(j = 0; j < i; j++) // Imp Step
			if(array[i] >= array[j] && (longestLengthAtIndex[j] + 1) > longestLengthAtIndex[i]) {
				longestLengthAtIndex[i] = longestLengthAtIndex[j] + 1;
				previousIndexOf[i] = j;
			}

		if(longestLengthAtIndex[i] > maxLength)
			maxLength = longestLengthAtIndex[i];
	}
			
	for(i = 0; i < SIZE; i++) {
		if(longestLengthAtIndex[i] == maxLength) {
			int tempMaxLength = maxLength;
			int tempIndex = i;
			while(tempMaxLength > 0) {
				printf("%d, ", array[tempIndex]);
				tempIndex = previousIndexOf[tempIndex];
				tempMaxLength--;
			}
			printf("\n");
		}
	}
}
