#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool CheckRowCol(int sudoku[][9], int i, int j, int* array) {
	if(sudoku[i][j] != 0)
                                if(array[sudoku[i][j]] == 0)
                                        array[sudoku[i][j]] = sudoku[i][j];
                                else
                                        return false;
	return true;
}

bool Check(int sudoku[][9], int row, int col, bool iOrj) {
	int i = row, j = col;
	int array[10];
        memset(array, 0, 10*sizeof(int));
	
	if(!iOrj) {
		while(j < 9)
			if(!CheckRowCol(sudoku, i, j++, array))
				return false;
	}
	else {
                while(i < 9)
                    	if(!CheckRowCol(sudoku, i++, j, array))
				return false;
	}
	
	return true;
}

bool Check3x3(int sudoku[][9], int i) {
	int array[10];
        memset(array, 0, 10*sizeof(int));
	int j, k, col;
	
	for(col = 0; col < 9; col += 3) {
		for(j = i; j < i + 3; j++) {
			for(k = col; k < col + 3; k++)
				if(sudoku[j][k] != 0) {
					if(array[sudoku[j][k]] == 0)
                                        	array[sudoku[j][k]] = sudoku[j][k];
                                	else
                                        	return false;
				}
			}
		memset(array, 0, 10*sizeof(int));
	}
	return true;
}

bool CheckValid(int sudoku[][9]) {
	int i,j;
	for(i = 0; i < 9; i++) {
		if(!Check(sudoku, i, 0, false))
			return false;
		if(!Check(sudoku, 0, i, true))
                        return false;
		if(i%3 == 0 && !Check3x3(sudoku, i))
			return false;
	}

	return true;
}

void main() {
	int sudoku[9][9] = {
				{5,3,0,0,7,0,0,0,0},
				{6,0,0,1,9,5,0,0,0},
				{0,9,8,0,0,0,0,6,0},
				{8,0,0,0,6,0,0,0,3},
				{4,0,0,8,0,3,0,0,1},
                                {7,0,0,0,2,0,0,0,6},
                                {0,6,0,0,0,0,2,8,0},
                                {0,0,0,4,1,9,3,0,5},
                                {0,0,0,0,8,0,0,7,9},
				};
	if(CheckValid(sudoku))
		printf("Valid Sudoku\n");
	else
		printf("Invalid Sudoku\n");

	int i, j;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++)
			printf("%d,", sudoku[i][j]);
		printf("\n");
	}
}
