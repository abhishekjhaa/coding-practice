#include<stdio.h>

void Permute(int* array, int* originalArray, int length);

void PrintArray(int* array, int length) {
	int i;
	for(i = 0; i < length; i++) {
		if(i < length - 1)
			printf("%d,", array[i]);
		else
			printf("%d\n", array[i]);
	}
}

void SwapAndPrint(int index, int* array, int length) {
	int i;
	for(i = index+1; i < length; i++) {
		int temp = array[index];
		array[index] = array[i];
		array[i] = temp;
		
		PrintArray(array, length);
		Permute(array+index+1, array, length);

		temp = array[index];
                array[index] = array[i];
                array[i] = temp;
	}

}

void Permute(int* array, int* originalArray, int length) {
        if(array[0] == originalArray[length - 1])
                return;
        int index = array - originalArray;
        Permute(array+1, originalArray, length);
        SwapAndPrint(index, originalArray, length);
}


void main() {
	int array[] = {1,2,3};
	int length = 3;
	PrintArray(array, length);
        Permute(array, array, length);
}
