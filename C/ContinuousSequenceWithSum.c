#include<stdio.h>

void main() {
	int sum = 15;
	int small = 1;
	int big = 2;
	int tempSum = small + big;
	while(small <= (sum+1)/2 && big <= (sum+1)/2) {
		if(tempSum < sum)
			big++;		// We are adding the next number so that tempSum will increase.
		else if (tempSum > sum)
			small++;	// We are eliminating the previous number so that tempSum will decerase.
		else {
			int i;
			for(i = small; i <= big; i++) {
				printf("%d + ", i);
			}
			printf(" = %d\n", sum);
			big++;		// Imp Step. If we don't do this step we'll be in infinite loop.
		}
		int j;
		tempSum = 0;
		for(j = small; j <= big; j++)
			tempSum += j;	// Recalculating the tempSum.
	}
}
