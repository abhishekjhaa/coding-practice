/*Selection Rank is a well-known algorithm in computer science to find the ith smallest 
(or largest) element in an array in linear time. 

If the elements are unique, you can find the ith smallest element in expected O(n) time.*/

#include<stdio.h>

void PrintArray(int* array, int length);

void Swap(int* array, int i, int j) {
//	printf("Swapped %d & %d\n", array[i], array[j]);
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void FindKthLargestElement(int* array, int k, int start, int length) {
	if(length - start <= 1)
		return;
	int pivotIndex = (rand() % (length - start)) + start;
	int pivotValue = array[pivotIndex];
	int end = length - 1;
	Swap(array, end, pivotIndex);
	int i = start, j = start;
	for(i = start; i < end; i++) {
		if(array[i] > pivotValue)
			Swap(array, i, j++);
	}
	Swap(array, j, end);
	if(j == k - 1)
		return;
	else if(j > k - 1)
		FindKthLargestElement(array, k, start, j);
	else
		FindKthLargestElement(array, k, j + 1, length);	
}

void PrintArray(int* array, int length) {
	int count = 0;
        while(count < length)
                printf("%d, ", array[count++]);
	printf("\n");
}

void main() {
	int stream[] = {4,5,6,46,47,65,63,41,56,465,466};
	int k = 4;
	int newArray[(2*k - 1)]; // Extra space that we can use.
	int length = 11;
	int count = 0;
	int arrayCount = 0;
        while(count < length) {
		if(arrayCount < (2*k - 1)) {
			printf("%d, ", stream[count]);
			newArray[arrayCount++] = stream[count++];
		}
		else {
			FindKthLargestElement(newArray, k, 0, arrayCount);
			arrayCount = k;
		}
	}
	printf("\n");
	FindKthLargestElement(newArray, k, 0, arrayCount);
	count = 0;
	while(count < 2*k - 1)
		printf("%d, ", newArray[count++]);
	printf("\n");
	printf("Largest Kth = %d Element is : %d\n", k, newArray[k - 1]);
}
