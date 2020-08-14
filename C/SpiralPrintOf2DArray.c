#include<stdio.h>

#define ROW 4
#define COL 4

void PrintSpirally(int array[][COL]) {
	int row = 0;
	int col = 0;
	int rowLen = ROW;
	int colLen = COL;
	int temp = 0;
	
	while(rowLen > 0 && colLen > 0) {
		temp = colLen;
		while(temp-- > 0 && rowLen > 0 && colLen > 0) {
			printf("%d, ", array[row][col++]);

		}
		
		rowLen--;
		col--;
		row++;

		temp = rowLen;
		while(temp-- > 0 && rowLen > 0 && colLen > 0) {
                        printf("%d, ", array[row++][col]);
                }

		colLen--;
		row--;
		col--;
		
		temp = colLen;		
		while(temp-- > 0 && rowLen > 0 && colLen > 0) {
                        printf("%d, ", array[row][col--]);
                }

		rowLen--;
		col++;
		row--;
        
		temp = rowLen;
		while(temp-- > 0 && rowLen > 0 && colLen > 0) {
                        printf("%d, ", array[row--][col]);
                }

                colLen--;
                row++;
                col++;
	}
	
	printf("\n");
}

void main() {
	int array[][COL] = {
				{ 1, 2, 3,4},
				{12,13,14,5},
				{11,16,15,6},
				{10, 9, 8,7}
						};
	PrintSpirally(array);
}
