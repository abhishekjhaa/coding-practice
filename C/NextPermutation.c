#include<stdio.h>

void PrintArray(int* array, int length) {
        int i;
        for(i = 0; i < length; i++) {
                if(i < length - 1)
                        printf("%d,", array[i]);
                else
                        printf("%d\n", array[i]);
        }
}

void Swap(int* array, int k, int l) {
	int temp = array[k];
	array[k] = array[l];
	array[l] = temp;
}

void Reverse(int* array, int start, int end) {
	while(start < end)
		Swap(array, start++, end--);
}

void FindNextPermutation(int* array, int length) {
	int k = length - 2;
	while(k >= 0 && array[k] >= array[k+1])
		k--;
	if(k == -1) {
		printf("This is the last permutation for the sequence\n");
		return;
	}

	int i, l;
	for(i = k+1; i < length; i++) {
		if(array[i] > array[k])
			l = i;
		else
			break;
	}

	Swap(array, k , l);

	Reverse(array, k+1, length-1);
	
	PrintArray(array, length);
}

void main() {
	int array[] = {1,0,3,2};
	int length = 4;
	PrintArray(array, length);
	FindNextPermutation(array, length);
}
