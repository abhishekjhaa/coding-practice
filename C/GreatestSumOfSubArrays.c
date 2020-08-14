/*You are given an array of integers (both positive and negative). Find the contiguous 
sequence with the largest sum. Return the sum. 
Cracking The Coding Interview 17.8*/

#include<stdio.h>

void main() {
	int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int length = sizeof(array)/sizeof(array[0]), greatestSum = 0, sum = 0, i = 0;
	
	while(i < length) {
		sum += array[i++];
		if(sum < 0)
			sum = 0;
		if(sum > greatestSum) 
			greatestSum = sum;
	}

	printf("Greatest Sum is : %d\n", greatestSum);
}
