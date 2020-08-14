#include<stdio.h>

void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void main() {
	int array[] = {1, 2, 3, 4, 5};
	int count = 5;
	int i = 0;
	int j = count - 1;
	while(i < j - 1) {
		while(array[i]%2 == 1)
			i++;
		while(array[j]%2 == 0)
			j--;
		Swap(array, i, j);
		i++;
		j--;
	}

	i = 0;
	while(array[i] && i < count) {
		printf("%d| ", array[i++]);
	}
	
	printf("\n");
}
