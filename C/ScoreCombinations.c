#include<stdio.h>
#include<malloc.h>

#define SIZE 3

static int count = 0;

void FindPermutationsOfScore(int totalScore, int minScore, int scorePossible[SIZE]) {
	if(totalScore < minScore)
		return;
	int i = 0;
	while(i < SIZE)  {
		if(totalScore - scorePossible[i] >= 0)
			if(totalScore - scorePossible[i] == 0)
				count++;
			else
				FindPermutationsOfScore(totalScore - scorePossible[i], minScore, scorePossible);
		
		i++;
	}
}

void Iterative(int totalScore, int scoreWays[SIZE]) {
	int permutations[totalScore + 1];
	permutations[0] = 1; // Only 1 way to reach 0
	int i = 1, j;
	while(i <= totalScore)
		permutations[i++] = 0;

	for(i = 0; i <= totalScore; i++)
		for(j = 0; j < SIZE; j++)
			if(i >= scoreWays[j])
				permutations[i] += permutations[i - scoreWays[j]];
	
	printf("Iterative : No of ways where a score of %d can be achieved = %d\n", totalScore, permutations[totalScore]);
}

void IterativeCombination(int totalScore, int scoreWays[SIZE]) {
        int combination[totalScore + 1];
        combination[0] = 1; // Only 1 way to reach 0
        int i = 1, j;
        while(i <= totalScore)
                combination[i++] = 0;

        for(j = 0; j < SIZE; j++)
		for(i = scoreWays[j]; i <= totalScore; i++)
        	        combination[i] += combination[i - scoreWays[j]];
        
        printf("Iterative : Combinations of score of %d is = %d\n", totalScore, combination[totalScore]);
}


void main() {
	int scoreWays[SIZE] = {2, 3, 7};
	int totalScore = 12;
	FindPermutationsOfScore(totalScore, 2, scoreWays);
	printf("No of ways where a score of %d can be achieved = %d\n", totalScore, count);

	Iterative(totalScore, scoreWays);
	IterativeCombination(totalScore, scoreWays);

}
