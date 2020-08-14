#include<stdio.h>

void Merge(int* array, int start, int middle, int end, int tempArray[], int* count) {
	int i = middle;
	int j = end;
	int k = end;
	while(i >= start && j > middle) {
		if(array[i] > array[j]) {
			*count += (j - middle);
			tempArray[k--] = array[i--]; 
		}
		else {
			tempArray[k--] = array[j--];
		}
	}

	while(i >= start) {
		tempArray[k--] = array[i--];
	}

	while(j > middle) {
		tempArray[k--] = array[j--];
	}	

	while(start <= end) {
		array[start] = tempArray[start];
		start++;
	}
}

void CountReversePairs(int array[], int start, int end, int* count) {
	if(start >= end)
		return;

	int  middle = (start + end) / 2;
	CountReversePairs(array, start, middle, count);
	CountReversePairs(array, middle + 1, end, count);
	int tempArray[end+1];
	Merge(array, start, middle, end, tempArray, count);
}

void main() {
	int array[] = {7,5,6,4};
	int length = 4;
	int newArray[4];
	int count = 0;
	CountReversePairs(array, 0, length - 1, &count);
	printf("Reverse Pairs are : %d\n", count);
}
