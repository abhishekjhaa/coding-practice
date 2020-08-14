#include<stdio.h>

void FindMaxIncreasingSubArray(int* array, int length, int* firstIndex, int* lastIndex) {
	int i = 0;
	int fIndex = 0, lIndex = 0;
	while(i < length - 1) {
		if(array[i+1] >= array[i]) {
			fIndex = i++;
			while(i < length - 1 && array[i+1] >= array[i])
				i++;
			lIndex = i;
		}

		if(lIndex - fIndex > *lastIndex - *firstIndex) {
			*firstIndex = fIndex;
			*lastIndex = lIndex;
		}

		i++;
	}
}

void main() {
	int array[] = {7,9,9,4,5,6,7,4,1,6,5};
	int length = 11;
	int firstIndex = 0,lastIndex = 0;
	FindMaxIncreasingSubArray(array, length, &firstIndex, &lastIndex);
	printf("Longest Increasing Sub Array Lies Between Index : %d & %d\n", firstIndex, lastIndex);
}
