#include<stdio.h>

void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void ArrangeNumbers(int* array, int index, int length) {
	int pivot = array[index];
	int i = 0;
	int j = length - 1;
	while(array[j] == pivot)
		j--;
	Swap(array, index, j--);
	int pivotIndex = j;
	while(i < j) {
		if(array[i] == pivot) {
			Swap(array, i, pivotIndex);
			pivotIndex--;
		}
		while(array[i] < pivot)
			i++;
		while(array[j] > pivot)
			j--;
		if(i < j)
			Swap(array, i, j);
	}

	pivotIndex++;
	while(pivotIndex < length)
		Swap(array, i++, pivotIndex++);

	for(i = 0; i < length; i++) {
                printf("%d, ", array[i]);
        }
        printf("\n");
}

void ArrangeNumbersMethodTwo(int* array, int index, int length) {
	int pivot = array[index];

	int equal = 0;
	int smaller = 0;
	int larger = length - 1;

	while(equal <= larger) {
		if(array[equal] < pivot) {
			if(array[smaller] != array[equal])
				Swap(array, smaller, equal);
			smaller++;
			equal++;			
		}
		else if(array[equal] == pivot)
				equal++;
		else {
			if(array[equal] != array[larger])
				Swap(array, equal, larger);
			larger--;
		}
	}
	
	int i;
 	for(i = 0; i < length; i++) {
                printf("%d, ", array[i]);
        }
        printf("\n");
}

void main() {
	int array[] = {1,2,4,6,5,3,4,5,7,8,5,9,3,6,7,3,5};
	int array2[] = {1,2,4,6,5,3,4,5,7,8,5,9,3,6,7,3,5};

	int i;
	for(i = 0; i < 17; i++) {
		printf("%d, ", array[i]);
	}
	printf("\n");
	ArrangeNumbers(array, 4, 17);
        ArrangeNumbersMethodTwo(array2, 4, 17);
}
