#include<stdio.h>

void Swap(int array[], int pivot, int end) {
	printf("Swapped %d %d\n", array[pivot], array[end]);
	int temp = array[pivot];
	array[pivot] = array[end];
	array[end] = temp;
}

void  GetMajorityElement(int array[], int start, int middle, int length) {
	if(length - start <= 1)
		return;
	int end = length - 1;
	int pivot = (rand() % (length - start)) + start;
	int pivotValue = array[pivot];
	if(array[pivot] != array[end])
		Swap(array, pivot, end);
	int i, j = start;
	for(i = start; i < end; i++) {
		if(array[i] < pivotValue) {
				if(i != j && array[i] != array[j])
					Swap(array, i, j);
				j++;
		}
	}
	if(j < end && array[j] != array[end])
		Swap(array, end, j);

	if(j == middle)
		return;
	if(j > middle)
		GetMajorityElement(array, start, middle, j);
	else
		GetMajorityElement(array, j + 1, middle, length);
}

void main() {
	int array[] = {1,2,2,3,2,2};
	int length = 6;
	int count = 0;
	while(count < length)
		printf("%d, ", array[count++]);
	printf("\n");
	int middle =  (length - 1) / 2;
	GetMajorityElement(array, 0, middle, length);
	printf("Majority element in the array is %d \n", array[middle]);
	count = 0;
        while(count < length)
                printf("%d, ", array[count++]);
	printf("\n");
}
