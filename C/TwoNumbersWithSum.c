#include<stdio.h>

void main() {
	int array[] = {1,2,4,7,11,15};
	int length = 6;
	int sum = 15;
	int i = 0; 
	int j = length - 1;
	int tempSum;
	while(j > i) {
		tempSum = array[i] + array[j];
		if(tempSum == sum) {
			printf("Sum found for %d as %d + %d\n", sum, array[i], array[j]);
			return;
		}
		else if (tempSum > sum)
			j--;
		else
			i++;
	}
	
	printf("Sum Not Found\n");
}
