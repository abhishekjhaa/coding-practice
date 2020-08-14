#include<stdio.h>

int SearchSequentially(int array[], int start, int end) {
	int result = array[start++];
	int i;	
	for(i = start; i <= end; i++) {
		if(array[i] < result)
			result = array[i];
	}

	return result;
}

int FindMinimum(int array[], int length) {
	int start = 0, middle = 0 ,end = length - 1;
	while(start <= end) {
		if(end - start == 1) {
			middle = end;
			break;
		}
		middle = start + (end - start)/2;
		if(array[start] == array[middle] && array[middle] == array[end])
			return SearchSequentially(array, start, end);
		if(array[start] <= array[middle])
			start = middle;
		if(array[end] >= array[middle])
			end = middle;
		middle = (start + end)/2;
	}

	return array[middle];
}

void main() {
	int array[] = {5, 6, 8, 9, 2};
	int length = 5;
	int result = FindMinimum(array, length);
	printf("Minimum of the Array is : %d \n", result);
}
