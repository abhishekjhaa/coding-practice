#include<stdio.h>
#include<stdbool.h>

#define NOOFUSERS 1000
#define NOOFSERVERS 10

bool GreedyAssignment(int* users, int limit, int* servers) {
	int serverIndex = 0, i;
	for(i = 0; i < NOOFUSERS; i++) {
		while(serverIndex < NOOFSERVERS && (users[i] + servers[serverIndex]) > limit) // Imp Step
			serverIndex++;
		if(serverIndex >= NOOFSERVERS)
			return false;
		else
			servers[serverIndex] += users[i]; 
	}

	return true;
}

void DecideLoadBalancing(int* users, int* servers) {
	// Uses binary search to find the assignment with minimized maximum load.
    	int l = 0, r = 0, i = 0;
	while(i < NOOFUSERS) {
		r += users[i++]; // aggregating all the memory required
	}
	while(l <= r) {
		int m = l + (r - l)/2;
		for(i = 0; i < NOOFSERVERS; i++)
			servers[i] = 0; // initializing the load on each server as 0
		
		bool isFeasible = GreedyAssignment(users, m, servers);
		
		if(isFeasible)
			r = m - 1;
		else
			l = m + 1;
	}
}

void main() {
	int users[NOOFUSERS];
	int servers[NOOFSERVERS];
	int i = 0, temp = 0;
	while(i < NOOFUSERS) {
		int memoryRequiredByUser = (rand() % 100) + 1;
		users[i++] = memoryRequiredByUser;
		temp += memoryRequiredByUser;
	}
	
	printf("Total memory Required %d\n", temp);
	temp = 0;

	DecideLoadBalancing(users, servers);

	for(i = 0; i < NOOFSERVERS; i++) {
		printf("Load on SERVER%d %d\n", i + 1, servers[i]);
		temp += servers[i];
	}

        printf("Total memory got : %d\n", temp);
}
