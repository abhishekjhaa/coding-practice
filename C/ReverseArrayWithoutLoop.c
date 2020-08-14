#include<stdio.h>

void PrintArray(int* array, int length) {
	int i;
	for(i = 0; i < length; i++)
                printf("%d, ", array[i]);
	printf("\n");
}

void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void Reverse(int* array, int start, int end) {
	if(end - start <= 1) {
		Swap(array, start, end);
		return;
	}
		
	Reverse(array, start + 1, end - 1);
	Swap(array, start, end);
}

void main() {
	int array[] = {1, 3, 5, 7, 2};
	int length = sizeof(array)/sizeof(array[0]);
	PrintArray(array, length);
	Reverse(array, 0, length - 1);
	int i;
	PrintArray(array, length);
}
