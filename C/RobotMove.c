#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>

#define ROW 6
#define COL 6

int DetermineSteps(int array[], bool* visited, int i, int j, int k) {
	int count = 0;
	if(array[i*COL + j] < k && visited[i*COL + j] == 0) {
		count++;
		visited[i*COL + j] = 1;
                printf("Array value %d at (%d,%d) is visited : %d \n", array[i*COL+j], i, j, visited[i*COL + j]);
		return count + ((i - 1) > -1  ? DetermineSteps(array, visited, i - 1, j, k) : 0)
			     + ((j - 1) > -1  ? DetermineSteps(array, visited, i, j - 1, k) : 0)
			     + ((i + 1) < ROW ? DetermineSteps(array, visited, i + 1, j, k) : 0)
			     + ((j + 1) < COL ? DetermineSteps(array, visited, i, j + 1, k) : 0); 
	}
	
	return count;
}

void main() {
	int array[ROW*COL];
	memset(array, 0, ROW*COL);
	bool visited[ROW*COL];
	memset(visited, 0, ROW*COL);
	int i, j, k, result;
	k = 6;
	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			array[i*COL + j] = i%10 + i/10 + j%10 + j/10;
        for(i = 0; i < ROW; i++)
                for(j = 0; j < COL; j++) {
		        printf("%d| ", array[i*COL + j]);
			if(j == COL - 1)
				printf("\n");
		}
	//for(i = 0; i < ROW; i++)
          //      for(j = 0; j < COL; j++)
			result = DetermineSteps(array, visited, 0, 0, k);
	printf("From (0,0) a ROBOT can move %d Cells \n", result);
}
