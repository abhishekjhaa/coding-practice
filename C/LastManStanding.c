/*
Men numbered from 1 to n are arranged in a circle in clockwise 
order. Every k-th man is removed, until only one man remains. What is the number of last man standing.
*/

#include<stdio.h>

#define N 100
#define K 4

void main() {
	int men[N], i;
	for(i = 0; i < N; i++)
		men[i] = 1;	// 1 means the man is standing.

	int k = K, count = 0;
	i = 0;
	while(1) {
		while(k > 1) {	// Gets the next man to be killed
			if(men[i] == 1)
				k--;
			if(i == N - 1)
				i = 0;
			else
				i++;
		}

		while(men[i] == 0) {	// If the next man has already been killed then search for next standing man.
			if(i == N - 1)
                                i = 0;
                        else
                                i++;
		}

		if(count == N - 1) {
                        printf("%dth man survives out of %d when K = %d\n", i+1, N, K);
                        return;
                }

		men[i] = 0; // Kill the man.
		count++;
		k = K;
	}	
}
