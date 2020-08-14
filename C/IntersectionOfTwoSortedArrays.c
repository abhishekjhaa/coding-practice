#include<stdio.h>
#include<string.h>

#define SIZEA 9
#define SIZEB 6

void FindInterSection(int* arrayA, int* arrayB, int* arrayC) {
	int lengthA = SIZEA, lengthB = SIZEB;
	int i = 0, j = 0, k = 0;
	while(i < lengthA && j < lengthB) {
		while(i < lengthA && j < lengthB && arrayA[i] < arrayB[j])
			i++;
		while(i < lengthA && j < lengthB && arrayB[j] < arrayA[i])
			j++;
		if(i < lengthA && j < lengthB && arrayA[i] == arrayB[j])
			arrayC[k++] = arrayA[i];
		i++;
		j++;
	}
}

// Two arrays are sorted. Find their intersection.
void main() {
	int arrayA[SIZEA] = {2,3,4,5,6,7,8,9,10};
	int arrayB[SIZEB] = {1,2,4,5,8,11};
	int SIZEC = SIZEA < SIZEB ? SIZEA : SIZEB;
	int arrayC[SIZEC];
	int count = 0;
	while(count < SIZEC)
		arrayC[count++] = -1;
	FindInterSection(arrayA, arrayB, arrayC);
	count = 0;
	while(count < SIZEC) {
		if(arrayC[count] != -1) 
			printf("%d, ", arrayC[count]);
		count++;
	}
	printf("\n");
}
