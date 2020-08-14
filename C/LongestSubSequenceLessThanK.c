#include<stdio.h>

#define SIZE 10

void main() {
	int array[SIZE] = {431, -15, 639, 342, -14, 565, -924, 635, 167, -70};
	int k = 184;
	int i = 0, sum = 0, j, maxLength = 0, startIndex = 0, endIndex = 0;
	array[-1] = 0;
	while(i < SIZE) {
		sum += array[i];
		if(sum > k)
			sum = 0; // Imp step
		else {
			j = i;
			int tempSum = 0, tempLength = 0;
			while(j >= 0) { // Imp Step.
				tempSum += array[j--];
				tempLength++;
				if(tempSum < k && tempLength > maxLength) {
					maxLength = tempLength;
					startIndex = j + 1;
					endIndex = i;
				}
			}
		}

		i++;
	}

	printf("Sum of Numbers less than %d lies between index [%d & %d]\n", k, startIndex, endIndex);
}
