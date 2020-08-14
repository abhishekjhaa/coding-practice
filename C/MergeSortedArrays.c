#include<stdio.h>

// Supposing there is enough memory at the end of array1,
// in order to accommodate numbers in array2
void merge(int* array1, int length1, int* array2, int length2) {
 	int index1, index2, indexMerged;
 	if(array1 == NULL || array2 == NULL)
 		return;
 	index1 = length1 - 1;
 	index2 = length2 - 1;
 	indexMerged = length1 + length2 - 1;
 	while(index1 >= 0 && index2 >= 0) {
 		if(array1[index1] >= array2[index2])
 			array1[indexMerged--] = array1[index1--];
 		else
		 array1[indexMerged--] = array2[index2--];
 	}
 	while(index2 >= 0)
 		array1[indexMerged--] = array2[index2--];
}

int main() {
	int array1[20] = {2,5,8,12,15,16,18, 23 };
	int array2[] = {3,4,7,9,10,13,17};

        int array2Length = sizeof(array2)/sizeof(array2[0]);
	int i = 0;
	while(array1[i++] != NULL);

	printf("%d %d \n", array2Length, i);

	merge(array1, i - 1, array2, array2Length);

	i = 0;
        while(array1[i++] != NULL) {
		printf("%d, ", array1[i]);
	}
	printf("\n");

}
