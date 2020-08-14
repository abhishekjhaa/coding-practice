#include<stdio.h>

void main() {
	int array[] = {4, 3, 2, 1, 2, 3, 6};
	int numberToRemove = 2;
	int count = 7;
	int i = 0;
	int j = count - 1;
	while(i < j - 1) {
		while(array[i] != numberToRemove)
			i++;
		while(array[j] == numberToRemove)
			j++;
		array[i] = array[j];
		array[j] = -1;
		i++;
		j--;
	}
	count = 0;
	while(array[count] > 0)
		printf("%d| ", array[count++]);
	printf("\n");
}
