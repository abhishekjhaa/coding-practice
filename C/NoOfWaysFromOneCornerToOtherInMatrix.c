#include<stdio.h>

// start from top left corneer of matrix and try to reach bottom right corner.
// You can only move right or down

#define N 5
#define M 5

static int count = 0;

void UsingRecursion(int array[N][M], int i , int j) {
	if(i == N - 1 && j == M - 1)
		count++;
	if(i < N -  1)
		UsingRecursion(array, i + 1, j);
	if(j < M - 1)
		UsingRecursion(array, i, j + 1);
}

void UsingRecursionWithObstacles(int array[N][M], int i , int j) {
        if(i == N - 1 && j == M - 1)
                count++;
        if(i < N -  1 && array[i + 1][j] != 1)
                UsingRecursionWithObstacles(array, i + 1, j);
        if(j < M - 1 && array[i][j + 1] != 1)
                UsingRecursionWithObstacles(array, i, j + 1);
}


void main() {
	int noOfWays[N][M];
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			noOfWays[i][j] = 0;
	
	// No of ways we get to (0, 0) is 1
        noOfWays[0][0] = 1;	

	for(i = 0; i < N; i++)
                for(j = 0; j < M; j++)
                        noOfWays[i][j] += (j < 1 ? 0 : noOfWays[i][j - 1]) + (i < 1 ? 0 : noOfWays[i - 1][j]);
	printf("NO of ways to reach bottom right corner from top left = %d\n", noOfWays[N - 1][M - 1]);

	UsingRecursion(noOfWays, 0, 0);
	printf("Using Recursion : %d\n", count);

	// Where ever there is 1 we can't pass through that cell
	int arrayWithObstacles[N][M] = {	{ 0,1,0,0,0 },
                                		{ 0,1,0,1,0 },
                                		{ 0,0,0,0,0 },
                                		{ 1,0,1,0,0 },
                                		{ 1,0,1,0,0 }	};
	count = 0;
	UsingRecursionWithObstacles(arrayWithObstacles, 0, 0);
	printf("Using Recursion With Obstacles : %d\n", count);	

	for(i = 0; i < N; i++)
                for(j = 0; j < M; j++)
                        noOfWays[i][j] = 0;

        // No of ways we get to (0, 0) is 1
        noOfWays[0][0] = 1;
	for(i = 0; i < N; i++)
                for(j = 0; j < M; j++)
			if(arrayWithObstacles[i][j] == 0)
                        	noOfWays[i][j] += (j < 1 ? 0 : noOfWays[i][j - 1]) + (i < 1 ? 0 : noOfWays[i - 1][j]);
        printf("NO of ways to reach bottom right corner from top left with Obstacles = %d\n", noOfWays[N - 1][M - 1]);

}
