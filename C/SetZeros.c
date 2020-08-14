/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and 
column are set to 0.
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define ROW 4
#define COL 4

void PrintArray(int array[][COL]) {
        int i,j;
        for(i = 0; i < ROW; i++) {
                for(j = 0; j < COL; j++)
                        printf("%d,", array[i][j]);
                printf("\n");
        }
}

void UsingArrays(int array[ROW][COL]) {
	bool row[ROW], col[COL];
	memset(row, false, ROW*sizeof(bool));
	memset(col, false, COL*sizeof(bool));
	int i, j;
	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			if(array[i][j] == 0) {
				row[i] = true;
				col[j] = true;
			}
	PrintArray(array);
	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			if(row[i] || col[j])
				array[i][j] = 0;
	PrintArray(array);
}

void UsingBitVector(int array[ROW][COL]) {
	// Saves space instead of usings two bool arrays 
	//we are using 2 ints and doing bit manupulation on it.
	// Only applicable if ROW & COL size are less than 32.
	if(ROW > 31 || COL > 31)
		return;

	int row = 0, col = 0;
	int i, j;
        for(i = 0; i < ROW; i++)
                for(j = 0; j < COL; j++)
                        if(array[i][j] == 0) {
                                row |= (1 << i);
                                col |= (1 << j);
                        }
	
	for(i = 0; i < ROW; i++)
                for(j = 0; j < COL; j++)
                        if((row >> i) & 1 == 1 || (col >> j) & 1 == 1)
                                array[i][j] = 0;
        PrintArray(array);
}

void SetZeros(int array[ROW][COL]) {
	int copyArray[ROW][COL];
	int i, j;
        for(i = 0; i < ROW; i++)
                for(j = 0; j < COL; j++)
                        copyArray[i][j] = array[i][j];

	UsingArrays(array);
	UsingBitVector(copyArray); 
}

void main() {

        int array[][COL] = {    { 1, 2, 3, 4},
                                { 5, 6, 0, 8},
                                { 9, 0,11,12},
                                {13,14,15,16}	};
	SetZeros(array);	
}
