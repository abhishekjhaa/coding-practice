#include<stdio.h>

void main() {
	int number1 = 10;
	int number2 =13;
	int temp = number1 ^ number2;
 	// the number of 1 bits in temp
 	int bits = 0;
 	while(temp != 0) {
 		++bits;
 		temp = (temp - 1) & temp;
 	}

	printf("To convert %d to %d, %d bits needed to be modified\n", number1, number2, bits);
}
