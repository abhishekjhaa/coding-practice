/*Write an algorithm to print all ways of arranging eight queens on an 8x8 chess 
board so that none of them share the same row, column or diagonal. In this case, 
"diagonal" means al/ diagonals, notjust the two that bisect the board. */

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
 
#define ROW 8
#define COL 8
#define N 8	//You can change the N to any number. Also you have to change the ROW & COL to respective number N.

bool CheckValid(int board[ROW][COL], int row, int col) {
	int i, j;
	/*Check if (row, column) is a valid spot for a queen by checking 
	if there is a queen in the same column or diagonal.(IMP: WE DONT NEED TO CHECK ROW) 
	we don't need to check it for queens in the same row because the calling 
	place Queen only attempts to place one queen at a time. We know 
	this row is empty. */
        
	// Check Column & Diagonals
        for(i = 0; i < row; i++) {
                if(board[i][col] != 0)
                        return false;
	
		/* Check diagonals: if the distance between the columns 
		* equals the distance between the rows, then they're in the 
		* same diagonal. */ 
		for(j = 0; j < COL; j++)
			if(board[i][j] && abs(j - col) == abs(row - i))
				return false;
	}
/*
        // Check Diagonal  - Naive Way
        for(i = 1; i < ROW; i++) {
                if(row + i < ROW && col + i < COL && board[row+i][col+i] != 0)
                        return false;
                if(row - i >= 0 && col - i >= 0 && board[row-i][col-i] != 0)
                        return false;
                if(row - i >= 0 && col + i < COL && board[row-i][col+i] != 0)
                        return false;
                if(row + i < ROW && col - i >= 0 && board[row+i][col-i] != 0)
                        return false;
        }
*/
	return true;
}

static int Count = 0;

bool PlaceQueens(int board[ROW][COL], int row, int queensLeft) {
	int i, j, col;
	if(queensLeft == 0) {
		Count++;
		printf("Board No : %d\n", Count);
		for(i = 0; i < ROW; i++) {
			for(j = 0; j < COL; j++)
				printf("%d, ", board[i][j]);
			printf("\n");
		}
		printf("\n");
		return true;
	}

	for(col = 0; col < COL; col++) {
		if(CheckValid(board, row, col)) {
			board[row][col] = 1;
			if(PlaceQueens(board, row + 1, queensLeft - 1)) {
				board[row][col] = 0; 	// If you want to dispaly all the possible variations.
			}				// Else leave it as blank OR comment it out
			else
				board[row][col] = 0;
		}
	}

	return false;
}

void main() {
	int chessBoard[ROW][COL];
	memset(chessBoard, 0, ROW*COL*sizeof(int));
	int noOfQueens = N;
	PlaceQueens(chessBoard, 0, noOfQueens);
}
