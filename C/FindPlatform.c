//http://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
#include<stdio.h>

void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void Sort(int* array, int start, int n) {
	if(start >= n - 1)
		return;
	int pivotIndex = (rand() % (n - start)) + start;
	int pivot = array[pivotIndex];
	Swap(array, pivotIndex, n - 1);
	int i = start, j = start;
	while(i < n - 1) {
		if(array[i] < pivot)
			Swap(array, i, j++);
		i++;
	}

	Swap(array, j, n - 1);
	Sort(array, start, j);
	Sort(array, j + 1, n);
}

int FindMinPlatForms(int* arr, int* dep, int n) {
	Sort(arr, 0, n);
	Sort(dep, 0, n);
	int i = 1 , j = 0, result = 1, platform = 1;
	while(i < n && j < n) {
		if(arr[i] < dep[j]) {
			platform++;
			i++;
			if(platform > result)
				result = platform;
		}
		else {
			platform--;
			j++;
		}
	}

	return result;
}

void main() {
	int arrival[] = {900, 940, 950, 1100, 1500, 1800};
	int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
	int size = sizeof(arrival)/sizeof(arrival[0]);
	int result = FindMinPlatForms(arrival, departure, size);
	printf("No Of Platforms needed = %d\n", result);
}
