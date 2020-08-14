/*
Given an image represented by an NxN matrix, where each pixel in the image is 4 
bytes, write a method to rotate the image by 90 degrees. Can you do this in place? 
*/

#include<stdio.h>
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

void Rotate90(int array[][COL]) {
	int rowStart = 0, rowEnd = ROW - 1, colStart = 0, colEnd = COL - 1, rowLen = ROW, colLen = COL;
	while(rowLen > 0 && colLen > 0) {
		int i = rowStart, j = colStart,	temp[rowLen], count = 0;
		while(i < rowEnd) {
			temp[count++] = array[i][colEnd];
			array[i++][colEnd] = array[rowStart][j++];
		}

		i = rowStart, count = 0, j = colEnd;
		while(j > colStart) {
			int k = temp[count];
                        temp[count++] = array[rowEnd][j];
                        array[rowEnd][j--] = k;
               	}
		
		i = rowEnd, count = 0, j = colEnd;
                while(i > rowStart) {
                        int k = temp[count];
                        temp[count++] = array[i][colStart];
                        array[i--][colStart] = k;
                }
		
		i = rowEnd, count = 0, j = colStart;
                while(j < colEnd) {
                        array[rowStart][j++] = temp[count++];
                }

		colStart += 1;
		rowStart += 1;
		colEnd -= 1;
                rowEnd -= 1;
		colLen -= 2;
		rowLen -= 2;
	}
}

main() {
	// Row&Col of Array should be 2^n.
	int array[][COL] = {
				{ 1, 2, 3, 4},
				{ 5, 6, 7, 8},
				{ 9,10,11,12},
				{13,14,15,16}
						};
	PrintArray(array);
	Rotate90(array);
	printf("90 degree Rotated Array Is : \n");
	PrintArray(array);
}
