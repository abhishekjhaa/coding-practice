#include<stdio.h>

int BinarySearch(int* array, int element, int start, int length) {
	int l = start;
	int u = length - 1;
	while(l <= u) {
		int m = l + (u - l) / 2;
//		printf("m = %d & array[m] = %d\n", m , array[m]);
		if(array[m] == element)
			return m;
		else if(array[m] > element)
			u = m - 1;
		else
			l = m + 1;
	}
	
	return -1;	
}

// Need to find 1st Occurence of K in the array.
void main() {
	int array[] = {-49, 75, 103, -147, 164, -197, -238, 314, 348, -422};
	int length = 10;
	int sum = 167;
	int i, index;
	for(i = 0; i < length; i++) {
		int elementToBeSearched = sum - array[i];
		index = BinarySearch(array, elementToBeSearched, i + 1, length);
		if(index != -1)
			break;
	}

	if(index >= 0)
		printf("For sum %d element at indexes %d & %d i.e., %d + %d gets the required value\n", sum, i, index, array[i], array[index]);
	else
		printf("For sum %d no pairs founds\n", sum);
}
