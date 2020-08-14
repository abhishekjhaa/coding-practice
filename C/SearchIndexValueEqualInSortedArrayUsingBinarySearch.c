#include<stdio.h>

int BinarySearch(int* array, int length) {
	int l = 0;
	int u = length - 1;
	int result = -1;
	while(l <= u) {
		int m = l + (u - l) / 2;
//		printf("m = %d & array[m] = %d\n", m , array[m]);
		if(array[m] == m) {
			return m;
			u = m - 1;
		}
		else if(array[m] > m)
			u = m - 1;
		else
			l = m + 1;
	}
		return -1;	
}

// Need to find 1st Occurence of K in the array.
void main() {
	int array[] = {-14, -10, 2, 108, 243, 285, 401};
	int length = 7;
	int element = 108;
	int index = BinarySearch(array, length);
	if(index >= 0)
		printf("For index %d Element %d is Equal to Index\n", index, array[index]);
	else
		printf("No such Index found where array[index] == index\n");
}
