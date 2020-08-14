#include<stdio.h>
#include<limits.h>

#define SIZE 9

typedef struct Range {
	int lowerIndex;
	int upperIndex;
} Range;

void CircularArray(int* array) {
	int i, j = 0, maxSum = INT_MIN;
        Range range;
        while(j < SIZE) {
		int minIndex = -1, minSum = 0, sum = 0, count = 0;
		for(i = j; i < j || count <= 1; ) { // Imp step
                	sum += array[i];
                	if(minSum > sum) {
                        	minSum = sum;
                        	minIndex = i;
                	}

                	if(sum - minSum > maxSum) {
                        	maxSum = sum - minSum;
                        	range.lowerIndex = minIndex + 1;
                        	range.upperIndex = i;
                	}

			if(i == SIZE - 1) {
				count++;
				i = 0;
			}
			else
				i++;
        	}
		
		j++;
	}

        printf("For Circular Array Maximum Sum can be obtained between index %d & %d\n", range.lowerIndex, range.upperIndex);

}

void main() {
	int array[SIZE] = {904, 40, 523, 12, -335, -385, -124, 481, -31};
	int i, minIndex = -1, minSum = 0, sum = 0, maxSum = INT_MIN;
	Range range;
	for(i = 0; i < SIZE; i++) {
		sum += array[i];
		if(minSum > sum) {
			minSum = sum;
			minIndex = i;
		//	printf("%d, %d\n", minSum, minIndex);
		}

		if(sum - minSum > maxSum) {
			maxSum = sum - minSum;
			range.lowerIndex = minIndex + 1;
			range.upperIndex = i;
		//	printf("MaxSum = %d minSum = %d sum = %d\n", maxSum, minSum, sum);
		}
	}

	printf("Maximum Sum can be obtained between index %d & %d\n", range.lowerIndex, range.upperIndex);
	
	CircularArray(array);
}
