#include<stdio.h>

int CompareAt(int* array, int m, int length) {
	int leftIndex = m - 1;
	if(m == 0)
		leftIndex = m + length - 1;
	if(leftIndex >= 0 && array[m] < array[leftIndex])
                        return m;
	return -1;
}

int BinarySearchs(int* array, int length) {
	int l = 0;
	int u = length - 1;
	while(l <= u) {
		int m = l + (u - l)/2;
//		printf("l = %d & u = %d & m = %d & array[m] = %d\n", l, u, m, array[m]);
		if(CompareAt(array, m, length) != -1)
			return m;
		if(CompareAt(array, l, length) != -1)
			return l;
		if(CompareAt(array, u, length) != -1)
			return u;
		
		if(array[l] < array[m])
			l = m + 1;
		else if(array[u] > array[l])
			u = m - 1;
		else if(array[m] < array[l])
			u = m - 1;
		else
			l = m + 1;
	}
}

int BinarySearch(int* array, int length) {
        int l = 0;
        int u = length - 1;
        while(l < u) {
                int m = l + (u - l)/2;
//              printf("l = %d & u = %d & m = %d & array[m] = %d\n", l, u, m, array[m]);
                if(array[m] > array[u])
                        l = m+1;
                else
                        u = m;
        }

	return l;
}


//Find the starting Point
void main() {
	int array[] = {16, 32, 78, 98, 103, 203, 220, 6, 7, 8};
	int length = 10;
	int index = BinarySearch(array, length);

	if(index >= 0)
		printf("Cyclically Sorted Array Starts at index %d with value %d\n", index, array[index]);
	else
		printf("No Starting Point found\n");
}
