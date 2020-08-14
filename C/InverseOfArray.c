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

void Inverse(int* array, int length) {
	int i, prevIndex = 0, nextIndex = 0, prevNum = array[0];
	for(i = 0; i < length; i++) {
		nextIndex = prevNum;
		prevNum = array[nextIndex];
		array[nextIndex] =  prevIndex;
		prevIndex = nextIndex;
	}
}

void main() {
	int array[] = {1,3,0,2};
	int length = 4;
	printf("Original   Array : ");
	PrintArray(array, length);
	Inverse(array, length);
	printf("Inverse of Array : ");
	PrintArray(array, length);
	Inverse(array, length);
	printf("Inverse of Inverse Array = Original Array : ");
        PrintArray(array, length);
}
