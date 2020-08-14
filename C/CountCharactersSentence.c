#include<stdio.h>
#define SIZE 256

void main() {
	char* sentence= "bcdacebe";
	int array[SIZE], count = 0;
	while(count < SIZE)
		array[count++] = 0;
	count = 0;
	while(sentence[count] != '\0') {
		array[sentence[count++]] += 1;
	}
	count = 0;
	while(count < SIZE) {
		if(array[count] != 0)
			printf("(%c, %d), ", count, array[count]);
		count++;
	}
	printf("\n");
}
