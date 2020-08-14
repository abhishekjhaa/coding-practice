#include<stdio.h>

int add(int num1, int num2) {
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);
	
	return num1;
}

void main() {
	int num1 = 5;
	int num2 = 17;
	int result = add(num1, num2);
	printf("Sum of %d %d using bit operations is %d\n", num1, num2, result);	
} 
