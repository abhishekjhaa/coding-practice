#include<stdio.h>

static int count = 0;

// Doing Least Comparisions is the objective here.
void FindMinMax(int* array, int* min, int* max, int length) {
	if(length <= 1) {
		*min = array[0];
		*max = array[0];
	}

	int minIndex = array[0] > array[1] ? 1 : 0; // Only One Comparison is done.
	count++;
	int maxIndex = minIndex ^ 1;
	*min = array[minIndex];
	*max = array[maxIndex];
	int i = 2;
	while(i < length - 1) {
		int minIndex = array[i] < array[i + 1] ? 0 : 1;
		int maxIndex = minIndex ^ 1;
		int tempMin = array[i + minIndex];
		int tempMax = array[i + maxIndex];
		if(*min > tempMin)
			*min = tempMin;
		if(*max < tempMax)
			*max = tempMax;
		i += 2;
		count += 3; 
	}

	if(length & 1 == 1) { // number is odd
		if(*min > array[i])
			*min = array[i];
		if(*max < array[i])
			*max = array[i];
		
		count += 2;
	}
}

void main() {
	int array[] = {4,5,6,67,48,9,7,64,65,46,78,97,91};
	int min = 0, max = 0, length = 13;
	FindMinMax(array, &min, &max, length);
	printf("Min = %d & Max = %d of the Array.\n",min, max);
	printf("Ideal No of Comparisons to be done %d +- 1\nActual No Of Comparisons done %d\n", 3*length/2 - 2, count);
}
