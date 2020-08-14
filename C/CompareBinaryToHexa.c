/*
Write a function to check if the value of a binary number 
(passed as a string) equals the hexadecimal representation of a string.
*/

// If solution not compliing add -lm at the end of cc CompareBinaryToHexa.c -lm

#include<stdio.h>
#include<string.h>
#include<math.h>

#define BASE1 2
#define BASE2 16

int CharToDigit(char c) {
	if(c >= '0' && c <= '9')
		return c - '0';
	else if(c >= 'a' && c <= 'z')
			return c - 'a' + 10;
	else if(c >= 'A' && c <= 'Z')
			return c - 'A' + 10;
	return -1;
}

int ConvertToDecimal(char* str, int base) {
	if(base < 2)
		return -1;
	int length = strlen(str);
	int number = 0, i;
	for(i = length - 1; i >= 0; i--) {	//Scanning starts from last digit.
		int digit = CharToDigit(str[i]);
		if(digit == -1 || digit >= base)
			return -1;
		number += pow(base, (length - 1 - i))*digit; 	// imp step. if we do (number += number*base + digit)
								// then 0's in string wont be counted
	}

	printf("%s in decimal is %d\n", str, number);
	return number;
}

int CompareBinaryToHexa(char* binaryStr, char* hexaStr) {
	int num1 = ConvertToDecimal(binaryStr, BASE1);
	int num2 = ConvertToDecimal(hexaStr, BASE2);
	if(num1 < 0 || num2 < 0)
		return -1;
	if(num1 == num2)
		return 1;
}

void main() {
	char* binaryStr = "1011";
	char* hexaStr ="B";

	if(CompareBinaryToHexa(binaryStr, hexaStr) == 1)
		printf("%s & %s are equal\n", binaryStr, hexaStr);
	else
		printf("%s & %s are not equal\n", binaryStr, hexaStr);
}
