#include<stdio.h>
#include<stdbool.h>

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

int multiply(int num1, int num2) {
	bool minus = false;
	if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
		minus = true;
	if (num1 < 0)
		num1 = add(~num1, 1);
	if (num2 < 0)
		num2 = add(~num2, 1);
	int result = 0;
	while (num1 > 0) {
		printf("Num1 : %d Num2 : %d\n", num1, num2);
		if ((num1 & 1) != 0) {
			result = add(result, num2);
		}
		num2 = num2 << 1;
		num1 = num1 >> 1;
		printf("Num1 >> : %d Num2 << : %d Result : %d\n", num1, num2, result);
	}
	
	if (minus)
		result = add(~result, 1);
	
	return result;
}

void main() {
	int num1 = 5;
	int num2 = 17;
	int result = multiply(num1, num2);
	printf("Multiplication of %d %d using bit operations is %d\n", num1, num2, result);	
} 
