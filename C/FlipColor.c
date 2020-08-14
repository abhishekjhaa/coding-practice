#include<stdio.h>
#include<malloc.h>

#define ROW 9
#define COL 9

typedef struct Q {
	int row;
	int col;
	struct Q* next;
} Q;

Q* QNew(Q* z, int row, int col) {
	Q* q = malloc(sizeof(Q));
        q->row = row;
        q->col = col;
        q->next = z;
	z = q;
	
	return z;
}

void FlipColor(int array[][COL], int row, int col) {
	int flipColor = array[row][col];
	int newColor = !flipColor;
	
	Q* q = malloc(sizeof(Q));
	q->row = row;
	q->col = col;
	q->next = NULL;
	
	while(q) {
		int i = q->row;
		int j = q->col;
		q = q->next;
		if(array[i][j] == flipColor) {
			if(i > 0 && array[i - 1][j] == flipColor)
				q = QNew(q, i - 1, j);
			if(i < ROW - 1 && array[i + 1][j] == flipColor)
				q = QNew(q, i + 1, j);
			if(j > 0 && array[i][j - 1] == flipColor)
                        	q = QNew(q, i, j - 1);
                	if(j < COL - 1 && array[i][j + 1] == flipColor)
                        	q = QNew(q, i, j + 1);
			array[i][j] = newColor;
		}
	}
}

void main() {

	// 0's are white & 1's are black
	int array[ROW][COL] = {
                                {1,0,1,0,0,0,1,1,1},
                                {0,0,1,0,0,1,0,0,1},
                                {1,1,1,0,0,1,1,0,1},
                                {0,1,0,1,1,1,1,0,1},
                                {1,0,1,0,0,0,0,1,0},
                                {1,0,1,0,0,1,0,1,1},
                                {0,0,0,0,1,0,1,0,0},
                                {1,0,1,0,1,0,1,0,0},
                                {1,0,1,1,0,0,0,1,1},
                                };
	int i, j;
	for(i = 0; i < ROW; i++) {
                for(j = 0; j < COL; j++)
                        printf("%d,", array[i][j]);
                printf(" - Row %d \n", i);
        }
	
	int row = 4, col =5;
	printf("\nFlippled Color at Row = %d Col = %d\n\n", row, col);


	FlipColor(array, row, col);

	for(i = 0; i < ROW; i++) {
                for(j = 0; j < COL; j++)
                        printf("%d,", array[i][j]);
                printf(" - Row %d \n", i);
        }

}
