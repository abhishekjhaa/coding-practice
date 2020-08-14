#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include <string.h> /* memset */
#include <unistd.h> /* close */

#define ROW 3
#define COLUMN 4

bool HasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int* pathLength, bool* visited) {
	// if string matched
	if(str[(*pathLength)] == '\0')
		return true;

 	bool hasPath = false;
 	if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[(*pathLength)] && !visited[row * cols + col]) {
 		++(*pathLength);
 		visited[row * cols + col] = true;
 		hasPath = ((col - 1) > -1 ? HasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) : false) 
			|| ((row - 1) > -1 ? HasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) : false)
 			|| ((col + 1) < cols ? HasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) : false)
 			|| ((row + 1) < rows ? HasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) : false);
 		if(!hasPath) {
 			--(*pathLength);
 			visited[row * cols + col] = false;
 		}
 	}

 	return hasPath;
}

bool HasPath(char* matrix, int rows, int cols, char* str) {
	if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
		return false;
	bool visited[rows * cols];
 	memset(visited, 0, sizeof(bool) * rows * cols);

	int pathLength = 0;
	int row, col;
 	for(row = 0; row < rows; ++row) {
 		for(col = 0; col < cols; ++col) {
 			if(HasPathCore(matrix, rows, cols, row, col, str, &pathLength, visited))
				return true;
 		}
 	}
	
	free(visited);
	return false;
}

void main(){
	int row = ROW;
	int column = COLUMN;
	char matrix[] = "ABCESFCSADEE";
    	char* str = "BCCED";
	if(HasPath(matrix, row, column, str))
		printf("Path is found \n");
	else
		printf("Path is not found \n"); 
}	

