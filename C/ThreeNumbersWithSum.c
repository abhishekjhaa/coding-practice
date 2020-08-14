#include<stdio.h>

void main() {
	int array[] = {1,2,4,7,-11,15};
	int length = 6;
	int i = 0; 
	int j = length - 1;
	int tempSum;
	int k = 0;
	for(k = 0; k < length; k++) {
		int sum = (-1)*(array[k]);
		while(j > i) {
			if(i == k)
				i++;
			if(j == k)
				j--;
			tempSum = array[i] + array[j];
			if(tempSum == sum) {
				printf("Sum is 0 for %d + %d + %d\n", array[k], array[i], array[j]);
				return;
			}
			else if (tempSum > sum)
				j--;
			else
				i++;
		}

		i = 0;
		j = length - 1;
	}
	
	printf("Sum Not Found\n");
}
