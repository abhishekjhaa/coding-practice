#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define LEN 10
#define WID 10

typedef struct Coordinate {
	int i;
	int j;
} Point;

bool FindPath(int maze[LEN][WID], Point startPoint, Point endPoint, Point pathTraced[LEN*WID], int* index);

void FindPathHelper(int maze[LEN][WID], Point startPoint, Point endPoint, Point nextPoint, Point pathTraced[LEN+WID], int* index) {
        maze[startPoint.i][startPoint.j] = 0;
        pathTraced[(*index)++] = nextPoint;
        FindPath(maze, nextPoint, endPoint, pathTraced, index);
        (*index)--;
        maze[startPoint.i][startPoint.j] = 1;
}

static Point shortestPathTraced[LEN*WID];
static int count = INT_MAX;

bool FindPath(int maze[LEN][WID], Point startPoint, Point endPoint, Point pathTraced[LEN*WID], int* index) {
	if(startPoint.i == endPoint.i && startPoint.j == endPoint.j) {
		if(*index < count) {
			int k;
			for(k = 0; k < *index; k++)
				shortestPathTraced[k] = pathTraced[k];
			count = *index;			
		}
		return true;
	}
	
	if(startPoint.j + 1 < WID && maze[startPoint.i][startPoint.j + 1] == 1) {
		Point nextPoint = {startPoint.i, startPoint.j + 1};
		FindPathHelper(maze, startPoint, endPoint, nextPoint, pathTraced, index);
	}
	
	if(startPoint.j > 0 && maze[startPoint.i][startPoint.j - 1] == 1) {
                Point nextPoint = {startPoint.i, startPoint.j - 1};
                FindPathHelper(maze, startPoint, endPoint, nextPoint, pathTraced, index);
        }
	
	if(startPoint.i + 1 < LEN && maze[startPoint.i + 1][startPoint.j] == 1) {
                Point nextPoint = {startPoint.i + 1, startPoint.j};
                FindPathHelper(maze, startPoint, endPoint, nextPoint, pathTraced, index);
        }
        
	if(startPoint.i > 0 && maze[startPoint.i - 1][startPoint.j] == 1) {
                Point nextPoint = {startPoint.i - 1, startPoint.j};
                FindPathHelper(maze, startPoint, endPoint, nextPoint, pathTraced, index);
        }

	return false;
}

void main() {
	// 1 represents open cells and 0 represent closed cells
	int maze[LEN][WID] = {	{0, 1, 1, 1, 1, 1, 0, 0, 1, 1}, 
                        	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1}, 
                        	{0, 1, 0, 1, 1, 0, 0, 1, 0, 0}, 
                        	{1, 1, 1, 0, 0, 0, 1, 1, 0, 1}, 
                        	{1, 0, 0, 1, 1, 1, 1, 1, 1, 1}, 
                        	{1, 0, 0, 1, 1, 0, 1, 0, 0, 1}, 
                        	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1}, 
                        	{0, 1, 0, 1, 0, 1, 0, 1, 1, 1}, 
                        	{0, 1, 0, 0, 1, 1, 1, 0, 0, 0}, 
                        	{1, 1, 1, 1, 1, 1, 1, 0, 0, 1}	};
	
	Point startPoint = {9,0} ;
	Point endPoint = {0, 9};
	Point pathTraced[LEN*WID];
	int index = 0, k;
	FindPath(maze, startPoint, endPoint, pathTraced, &index);
	printf("Shortest Path Traced:\n");
	for(k = 0; k < count; k++) {
		printf("(%d, %d), ", shortestPathTraced[k].i, shortestPathTraced[k].j);
	}
	printf("\n");
}
