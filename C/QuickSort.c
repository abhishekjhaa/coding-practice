#include<stdio.h>

#define SIZE 9

void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void QuickSort(int* array, int start, int end) {
	if(start >= end - 1)
		return;
	int randIndex = rand() % (end - start) + start;
	
	int pivot = array[randIndex];
	Swap(array, randIndex, end - 1); // Push pivot to the last index.
	int i = start, j = start;
	while(j < end - 1) {
		if(array[j] < pivot)
			Swap(array, i++, j);
		j++;
	}

	Swap(array, i, end - 1); // Get back pivot to its old position.
	
	QuickSort(array, start, i);
	QuickSort(array, i + 1, end);
}

void main() {
	int array[SIZE] = { 7,9,6,4,5,1,3,8,2 };
	QuickSort(array, 0 , SIZE);
	int count = 0;
	while(count < SIZE) {
		printf("%d, ", array[count++]);
	}
	printf("\n");
}
