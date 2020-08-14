/*Given an array of length n, find a subarray of length k where the sum of all the elements 
in the subarray is greatest*/

#include<stdio.h>

#define N 10
#define K 4 // Test case : If K is 1 then the maximum element in the array will be returned.

void PrintArray(int array[], int length) {
	int i;
	for(i = 0; i < length; i++)
                printf("%d, ", array[i]);
        printf("\n");
}

void main() {
	int n = N, i;
	int array[n];
	for(i = 0; i < n; i++)
		array[i] = rand() % (n + (i % n));
	
	PrintArray(array, n);

	int cumulativeSumArray[n];
	cumulativeSumArray[0] = array[0];
	for(i = 1; i < n; i++)
		cumulativeSumArray[i] = cumulativeSumArray[i - 1] + array[i];

	PrintArray(cumulativeSumArray, n);

	int subArrayLength = K;
	int cumulativeSum = cumulativeSumArray[subArrayLength - 1];
	int index =  subArrayLength - 1;
	for(i = subArrayLength; i < n; i++) {
		// Check if sum of last K elements is greater than the stored sum of K elements
		if(cumulativeSumArray[i] - cumulativeSumArray[i - subArrayLength] > cumulativeSum) {
			cumulativeSum = cumulativeSumArray[i] - cumulativeSumArray[i - subArrayLength];
			index = i;
		}
	}

	for(i = index - (subArrayLength - 1); i <= index && i < n; i++)
                printf("%d, ", array[i]);
	printf("\n");

	// Runtime is O(n).
}
