/*Selection Rank is a well-known algorithm in computer science to find the ith smallest 
(or largest) element in an array in linear time. 

If the elements are unique, you can find the ith smallest element in expected O(n) time.*/

#include<stdio.h>

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
	int i = start, j = end - 1;
	while(i < j) {
		if(i < j && array[i] > pivotValue)
			i++;
		else if(i < j && array[j] < pivotValue)
			j--;
		else
			Swap(array, i++ , j--);
	}
	Swap(array, j, end);
	if(j == k - 1)
		return;
	else if(j > k - 1)
		FindKthLargestElement(array, k, start, j);
	else
		FindKthLargestElement(array, k, j + 1, length);	
}

void main() {
	int array[] = {4,5,6,46,47,65,63,41,56,465,466};
	int k = 3;
	int length = 11;
	int count = 0;
        while(count < length)
                printf("%d, ", array[count++]);
	printf("\n");
	FindKthLargestElement(array, k, 0, length);
	count = 0;
	while(count < length)
		printf("%d, ", array[count++]);
	printf("\n");
	printf("Largest Kth = %d Element is : %d\n", k, array[k - 1]);
}
