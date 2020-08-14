#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define N 8

bool CheckValid(int* board, int row, int col) {
	// Check Column & Diagonal
	int i;
	for(i = 0; i < row; i++) {
		int j = board[i]; // Imp: use i, not row
		if(j == col) // If columns are same
			return false;
		if(abs(row - i) == abs(col - j)) // if diagonals same.
			return false;
	}

	return true;
}

static int count = 0;

void PlaceQueens(int* board, int row) {
	if(row == N) {
		int i;
		for(i = 0; i < N; i++)
			printf("(%d, %d), ", i + 1, board[i] + 1);
		printf("\n");
		count++;
		return;
	}
		
	int col;
	for(col = 0; col < N; col++) {
		if(CheckValid(board, row, col)) {
			board[row] = col;
			PlaceQueens(board, row + 1);
		}
	}
}

void main() {
	int board[N];
	memset(board, -1, N*sizeof(int));
	int row = 0;
	PlaceQueens(board, row);
	printf("Total no of arrangements possible = %d\n", count);
}
