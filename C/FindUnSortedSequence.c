/*Given an array of integers, write a method to find indices m and n such that if you 
sorted elements m through n, the entire array would be sorted. Minimize n - m (that 
is, find the smallest such sequence). 
Cracking the coding Interview 17.6
*/

#include<stdio.h>

int FindIncreasingSubsequence(int* array, int start, int length) {
	while(start < length && array[start] < array[start + 1])
		start++;
	return start + 1;
}

int FindElementLessThanM(int* array, int start, int m) {
	int min = array[m];
	while(m >= start && array[m - 1] >= min)
			m--;
	return m;
}

int FindElementGreaterThanN(int* array, int n, int length) {
	int max = array[n - 1];
	while(n <= length && array[n] < max)
			n++;
	return n - 1;
}

void main() {
	int array[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
	int length = sizeof(array)/sizeof(array[0]);
	int start = 0;
	int m = FindIncreasingSubsequence(array, start, length);
	int n = FindIncreasingSubsequence(array, m, length);
	
	m = FindElementLessThanM(array, start, m);
	n = FindElementGreaterThanN(array, n, length);

	printf("n = %d m = %d n - m = %d\n", n, m, n - m);
}
