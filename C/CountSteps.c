/*A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or 
3 steps at a time. Implement a method to count how many possible ways the child 
can run up the stairs. */

#include<stdio.h>
#include<string.h>

#define N 35

int CountWays(int n) {
	if(n < 0)
		return 0;
	else if(n == 0)
		return 1;
	else
		return CountWays(n - 1) + CountWays(n - 2) + CountWays(n - 3);
}

int CountWaysDP(int n, int* cache) {
        if(n < 0)
                return 0;
        else if(n == 0)
                return 1;
	else if(cache[n] > 0)
		return cache[n];
        else {
                cache[n] = CountWaysDP(n - 1, cache) + CountWaysDP(n - 2, cache) + CountWaysDP(n - 3, cache);
		return cache[n];
	}
}

void main() {
	int steps[N+1];
	steps[0] = 0;
	steps[1] = 1; // There is only 1 way to climb 1st stair.
	steps[2] = 1 + steps[1]; // We can climb stair 2 directly for via step 1.
	steps[3] = 1 + steps[2] + steps[1]; // we can climb step 3 directly or via step 2 or via step 1
	
	int i;
	for(i = 4; i < N + 1; i++) { // This is the fastest since we are taking O(n) time.
		steps[i] = steps[i - 1] + steps[i - 2] + steps[i - 3];
	} 

	printf("No of ways to climb a %d number stair is %d\n", N, steps[N]);

	// Solved using Recursive way.
	int result = CountWays(N); // It'll take considerable amout of time.	
	printf("No of ways to climb a %d number stair is %d\n", N, result);

	// Solved using DP
	int cache[N + 1];
	memset(cache, 0, (N+1)*sizeof(int));
	result = CountWaysDP(N, cache); // It'll take very less time cause we are caching the intermediate results.
        printf("No of ways to climb a %d number stair is %d\n", N, result);
}
