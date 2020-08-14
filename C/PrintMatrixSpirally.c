#include<stdio.h>
#include<string.h>

void main() {
	int size = 4;
	int matrix[][4] = { 	{ 1,  2,  3,  4}, 
				{ 5,  6,  7,  8}, 
				{ 9, 10, 11, 12}, 
				{13, 14, 15, 16}	};

	int j = 0;
	int i = 0;
	int count = 0;
	int k;
	for(k = 0; k < size/2; k++) {
	while(j < size -  count)
		printf("%d| ", matrix[i][j++]);
	j--;
	i++;
	while(i < size - count)
		printf("%d| ", matrix[i++][j]);
	i--;
	j--;
	while(j > count - 1)
		printf("%d| ", matrix[i][j--]);
	j++;
	i--;
	while(i > count)
		printf("%d| ", matrix[i--][j]);
	i++;
	j++;
	
	count++;
	}
	printf("\n");
}
