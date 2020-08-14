#include<stdio.h>

#define SIZE 9

void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] =  array[j];
	array[j] = temp;
}

void QuickSort(int* array, int start, int end) {
	if(start >= end)
		return;
	int randomIndex = (rand() % (end - start)) + start;
	int pivot = array[randomIndex];
	Swap(array, randomIndex, end);
	int i = start, j = start;
	while(i < end) {
		if(array[i] < pivot)
			Swap(array, i, j++);
		i++;
	}

	Swap(array, j, end);
	
	QuickSort(array, start, j - 1);
	QuickSort(array, j + 1, end);
}

void main() {
	int executionTime[SIZE] = {7,8,9,3,2,1,6,5,4}; // Time taken by each query to excute.
	QuickSort(executionTime, 0, SIZE - 1); // Sort it based on execution time

	int i, totalWaitingTime = 0;
	for(i = 0; i < SIZE; i++) {
		printf("%d, ", executionTime[i]);
		totalWaitingTime += executionTime[i]*(SIZE - (i+1)); // All other remaining query have to wait while ith query gets processed.
	}

	printf("\nTotal Waiting Time for all queries to get processed = %d\n", totalWaitingTime);
}
