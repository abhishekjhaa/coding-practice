#include<stdio.h>

#define SIZE 9

void Merge(int* array, int start, int mid, int end) {
	int i = start, j = mid, k = 0;
	int tempArray[end - start];
	while(i < mid && j < end) {
		if(array[i] < array[j])
			tempArray[k++] = array[i++];
		else
			tempArray[k++] = array[j++];
	}

	while(i < mid) // First fill the remaining left side array beacuse it'll have smaller values than right hand side array.
		tempArray[k++] = array[i++];
	
	while(j < end) // Then push the right hand side array.
                tempArray[k++] = array[j++];

	i = 0;
	while(i < k)
		array[start++] = tempArray[i++];
}

void MergeSort(int* array, int start, int end) {
	if(start >= end - 1)
		return;
	int mid = start + (end - start)/2;
	MergeSort(array, start, mid);
	MergeSort(array, mid, end);

	Merge(array, start, mid, end);
}

void main() {
	int array[SIZE] = { 7,9,6,4,5,1,3,8,2 };
	MergeSort(array, 0 , SIZE);
	int count = 0;
	while(count < SIZE) {
		printf("%d, ", array[count++]);
	}
	printf("\n");
}
