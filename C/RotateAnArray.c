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

void Swap(int* array, int i , int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void Rotate(int* array, int length, int rotateRightBy) {
	int index = length - rotateRightBy;
	int temp = rotateRightBy;
	while(index > 0) {
		int start = index;
		int end = start + rotateRightBy;
		index = start - rotateRightBy;
		while(start < end) {
			if(start - rotateRightBy >= 0) {
				Swap(array, start, start - rotateRightBy);
				start++;
			}
			else
				rotateRightBy--;
		}
	}
	printf("Rotated Array by %d : ", temp);
	PrintArray(array, length);
}

void ReverseArray(int* array, int start, int end) {
	while(start < end)
		Swap(array, start++, end--);
}

void RotateByReverse(int* array, int length, int rotateRightBy) {
	int start = 0, end = length - 1;
	ReverseArray(array, start, end);
	ReverseArray(array, start, rotateRightBy - 1);
	ReverseArray(array, rotateRightBy, end);
	
	printf("Rotated Array by %d : ", rotateRightBy);
        PrintArray(array, length);
}

void main() {
	int array[] = {5,7,3,4,9,8,2,3,4};
	int array2[] = {5,7,3,4,9,8,2,3,4};
	int length = 9;
	int rotateRightBy = 4;
	printf("Original Array     : ");
	PrintArray(array, length);
	Rotate(array, length, rotateRightBy);
	RotateByReverse(array2, length, rotateRightBy);
}
