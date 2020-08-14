#include<stdio.h>

//Count Inversion if i < j && array[i] > array[j]

#define SIZE 9
static int count = 0;
void Merge(int* array, int start, int mid, int end) {
	int i = start, j = mid, k = 0;
	int tempArray[end - start];
	while(i < mid && j < end) {
		if(array[i] < array[j])
			tempArray[k++] = array[i++];
		else {
			int temp = i;
			//if i < j && array[i] > array[j] then all the elements at greater than i will also be
			// greater than element at j(since array is sorted).
			while(i < mid) {
				count++;
				printf("(%d, %d)\n", array[i++], array[j]);
			}
			i = temp;
			tempArray[k++] = array[j++];
		}
	}

	while(i < mid)
		tempArray[k++] = array[i++];
	
	while(j < end)
                tempArray[k++] = array[j++];

	i = 0;
	while(i < k) {
		array[start + i] = tempArray[i];
		i++;
	}
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
	//int array[SIZE] = {9,8,7,6,5,4,3,2,1};
	int i = 0;
        while(i < SIZE) {
                printf("%d, ", array[i++]);
        }
        printf("\n");
	printf("Inverted Pairs whose i < j && A[i] > A[j]\n");
	MergeSort(array, 0 , SIZE);
	printf("Total Inverted Pairs = %d\n", count);
	i = 0;
	while(i < SIZE) {
		printf("%d, ", array[i++]);
	}
	printf("\n");
}
