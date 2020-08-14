#include<stdio.h>
#include<math.h>

#define SIZE 30

void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void Insert(int* array, int data, int position) {
	array[position] = data;
	int parentPosition = floor((position - 1)/2);
	while(parentPosition >= 0 && position > 0 && array[parentPosition] >= array[position]) {
		Swap(array, position, parentPosition);
		position = parentPosition;
		parentPosition = floor((position - 1)/2);
	}
}

void PrintArray(int* array, int length) {
	int i = 0;
	while(i < length)
		printf("%d, ", array[i++]);
	printf("\n");
}

int GetMin(int* array, int length) {
	if(length < 1) {
		printf("Empty Heap\n");
		return;
	}

	int minIndex = 0;
	Swap(array, minIndex, length - 1);
	int childIndex1 = 2*minIndex + 1;
	int childIndex2 = childIndex1 + 1;
	while(childIndex2 < length - 1 && (array[minIndex] > array[childIndex1] || array[minIndex] > array[childIndex2])) {		
		int min = array[childIndex2] > array[childIndex1] ? childIndex1 : childIndex2;
		Swap(array, minIndex, min);
		minIndex = min;

		childIndex1 = 2*minIndex + 1;
        	childIndex2 = childIndex1 + 1;
	}
}

void main() {
	int array[SIZE];
	int i;
	int length = 0;
	for(i = 0; i < SIZE && length < SIZE; i++)
		Insert(array, rand()%SIZE + 1, length++);
	
	PrintArray(array, length);	
	for(i = 0; i < SIZE + 1; i++)
		GetMin(array, length--);
	
	// Sorted Array
	PrintArray(array, i - 1);
}
