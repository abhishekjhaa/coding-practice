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
	int num1 = 17;
	int num2 = 5;
	num2 = add(~num2, 1); // Here we get 5 as -5
	int result = add(num1, num2);
	printf("Substracting %d %d using bit operations is %d\n", num1, num2, result);	
} 
