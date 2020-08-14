#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

#define ROW 9
#define COL 9

bool IsValidToAdd(int sudoku[ROW][COL], int row, int col, int value) {
	int i, j;
	// Check Row
	for(i = 0; i < COL; i++)
		if(value == sudoku[row][i])
			return false;
	// Check Column
        for(i = 0; i < ROW; i++)
                if(value == sudoku[i][col])
                        return false;
	
	// Check Region
	int regionSize = sqrt(ROW);
	int baseRow =  row/regionSize;
	int baseCol = col/regionSize;
	for(i = regionSize * baseRow; i < regionSize * (baseRow + 1); i++) {
		for(j = regionSize * baseCol; j < regionSize * (baseCol + 1); j++)
			if(value == sudoku[i][j])
				return false;
	}

	return true;
}

static int countFlag = 0;

bool SolveSudoku(int sudoku[ROW][COL], int row, int col) {
	// We are checking up to down i.e., columnwise
	if(row == ROW) {
		row = 0; // Start a new Row
		col++;
		if(col == COL) {
			countFlag++;
			return true; // Entire Matrix has been filled without conflict
		}
	}

	if(sudoku[row][col] != 0) 
		SolveSudoku(sudoku, row + 1, col); // Skip if position is already filled
	
	int value;
	for(value = 1; value <= ROW; value++) {
		// It's substantially quicker to check if entry val conflicts
      		// with any of the constraints if we add it at (i,j) before
      		// adding it, rather than adding it and then checking all constraints.
      		// The reason is that we are starting with a valid configuration,
      		// and the only entry which can cause a problem is entryval at (i,j).
		if(IsValidToAdd(sudoku, row, col, value)) {
			sudoku[row][col] = value;
			if(SolveSudoku(sudoku, row + 1, col))
				return true;
		}
	}
	
	if(countFlag == 1)
              return true;

	sudoku[row][col] = 0;
	return false;		
}

bool CheckValid(int sudoku[ROW][COL]) {
	int i, j;
	// Check Row Constraints
	for(i = 0; i < ROW; i++) {
		int isPresent[COL + 1];
		memset(isPresent, 0, (COL + 1)*sizeof(int));
		for(j = 0; j < COL; j++)
			if(sudoku[i][j] != 0 && isPresent[sudoku[i][j]] == 1)
				return false;
			else
				isPresent[sudoku[i][j]] = 1;
	}

	// Check Column Constraints
	for(j = 0; j < COL; j++) {
                int isPresent[ROW + 1];
                memset(isPresent, 0, (ROW + 1)*sizeof(int));
                for(i = 0; i < ROW; i++)
                        if(sudoku[i][j] != 0 && isPresent[sudoku[i][j]] == 1)
                                return false;
                        else
                                isPresent[sudoku[i][j]] = 1;
        }

	// Check Region Constraints
	int regionSize = sqrt(ROW);
	int I, J;
	for(I = 0; I < ROW; I += regionSize)
		for(J = 0; J < COL; J += regionSize) {
			int isPresent[ROW + 1];
                	memset(isPresent, 0, (ROW + 1)*sizeof(int));
			for(i = I; i < I + regionSize; i++)
				for(j = J; j < J + regionSize; j++)
					if(sudoku[i][j] != 0 && isPresent[sudoku[i][j]] == 1)
						return false;
					else
						isPresent[sudoku[i][j]] = 1;
		}	
}

void main() {
/*	int sudoku[ROW][COL] = {	{5,3,0,0,7,0,0,0,0},
                                	{6,0,0,1,9,5,0,0,0},
                                	{0,9,8,0,0,0,0,6,0},
                                	{8,0,0,0,6,0,0,0,3},
                                	{4,0,0,8,0,3,0,0,1},
                                	{7,0,0,0,2,0,0,0,6},
                                	{0,6,0,0,0,0,2,8,0},
                                	{0,0,0,4,1,9,3,0,5},
                                	{0,0,0,0,8,0,0,7,9},	};
	int sudoku[ROW][COL] = {{0, 2, 6, 0, 0, 0, 8, 1, 0},
                      		{3, 0, 0, 7, 0, 8, 0, 0, 6},
                      		{4, 0, 0, 0, 5, 0, 0, 0, 7},
                      		{0, 5, 0, 1, 0, 7, 0, 9, 0},
                      		{0, 0, 3, 9, 0, 5, 1, 0, 0},
                      		{0, 4, 0, 3, 0, 2, 0, 5, 0},
                      		{1, 0, 0, 0, 3, 0, 0, 0, 2},
                      		{5, 0, 0, 2, 0, 4, 0, 0, 9},
                      		{0, 3, 8, 0, 0, 0, 4, 6, 0}};
*/
	int sudoku[ROW][COL] = {{1,2,0,4,0,0,3,0,0},
				{3,0,0,0,1,0,0,5,0},
				{0,0,6,0,0,0,1,0,0},
				{7,0,0,0,9,0,0,0,0},
				{0,4,0,6,0,3,0,0,0},
				{0,0,3,0,0,2,0,0,0},
				{5,0,0,0,8,0,7,0,0},
				{0,0,7,0,0,0,0,0,5},
				{0,0,0,0,0,0,0,9,8}};
	
	int i, j;
        for(i = 0; i < 9; i++) {
                for(j = 0; j < 9; j++)
                        printf("%d,", sudoku[i][j]);
                printf("\n");
        }
	if(CheckValid(sudoku)) {
		printf("Sudoku is Valid\n");
		SolveSudoku(sudoku, 0, 0);
		int i, j;
        	for(i = 0; i < 9; i++) {
                	for(j = 0; j < 9; j++)
                        	printf("%d,", sudoku[i][j]);
                	printf("\n");
        	}
	}
	else
		printf("Sudoku is Invalid\n");
}
