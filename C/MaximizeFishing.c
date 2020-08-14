#include<stdio.h>

// start from top left corneer of matrix and try to reach bottom right corner.
// You can only move right or down
// Where there is 1 it repesents the fish.

#define N 5
#define M 5

static int count = 0;

int Max(int a, int b) {
        return a > b ? a : b;
}

int UsingRecursion(int array[N][M], int i , int j) {
	if(i > N - 1 || j > M - 1)
		return 0;
	if(i == N - 1 && j == M - 1)
		return array[i][j];
	return array[i][j] + Max(UsingRecursion(array, i + 1, j), UsingRecursion(array, i, j + 1));
}

void main() {
	int i, j;
	// Where ever there is 1 we have fish.
	int array[N][M] = {	{ 0,0,0,0,0 },
                                { 0,0,1,0,0 },
                                { 0,0,0,0,0 },
                                { 1,0,0,0,1 },
                                { 0,0,0,0,1 } 	};

        int result = UsingRecursion(array, 0, 0);
        printf("Using Recursion %d\n", result);

	for(i = 0; i < N; i++)
                for(j = 0; j < M; j++)
                        array[i][j] += Max((j < 1 ? 0 : array[i][j - 1]), (i < 1 ? 0 : array[i - 1][j]));
        printf("Maximum fishes the fisherman can catch  = %d\n", array[N - 1][M - 1]);
}
