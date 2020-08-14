/*Imagine a robot sitting on the upper left corner of an X by Y grid. The robot can only 
move in two directions: right and down. How many possible paths are there for the 
robot to go from ( e, B) to (X, Y)? 
FOLLOW UP 
Imagine certain spots are "off limits," such that the robot cannot step on them. 
Design an algorithm to find a path for the robot from the top left to the bottom right. */

#include<stdio.h>
#include<string.h>

#define X 17
#define Y 17

int UsingRecursion(int grid[X][Y], int x, int y) {
	if(x < 0 || y < 0)
		return 0;
	if(x == 0 && y == 0)
		return 1;
	return UsingRecursion(grid, x - 1, y) + UsingRecursion(grid, x, y - 1);
}

int UsingRecursionDP(int grid[X][Y], int x, int y, int cache[X][Y]) {
        if(x < 0 || y < 0)
                return 0;
        else if(x == 0 && y == 0)
                return 1;
	else if(cache[x][y] != 0)
		return cache[x][y];
       else {
		cache[x][y] = UsingRecursionDP(grid, x - 1, y, cache) + UsingRecursionDP(grid, x, y - 1, cache);
		return cache[x][y];
	}
}

void main() {
	int grid[X][Y], i, j;
	memset(grid, 0, X*Y*sizeof(int));
	grid[0][0] = 1; // Start from here

	for(i = 0; i < X; i++) {
		for(j = 0; j < Y; j++) { // Takes O(m*n) time
			if((i - 1) >= 0)
				grid[i][j] += grid[i - 1][j];
			if((j - 1) >= 0)
				grid[i][j] += grid[i][j - 1];
		}
	}

	printf("%d\n", grid[X - 1][Y - 1]);

	// Using Recursion
	int result  = UsingRecursion(grid, X - 1, Y - 1);
	printf("%d\n", result);

	// Using DP
	int cache[X][Y];
	for(i = 0; i < X; i++)
                for(j = 0; j < Y; j++)
                        cache[i][j] = 0;
	result  = UsingRecursionDP(grid, X - 1, Y - 1, cache); // Since we are caching it is very fast than the nornmal recursion.
        printf("%d\n", result);
}
