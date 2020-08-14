#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void PrintNumber(char* number) {
 	char* pChar = number;
 	while(*pChar == '0')
 		++pChar;
 	if(*pChar != '\0')
 		printf("%s\t", pChar);
}
	
bool Increment(char* str, int length) {
	bool isOverflow = false;
	int carry = 0;
	int i;
	for(i = length - 1; i >= 0; i--) {
		int sum = str[i] - '0' + carry;
		if(i == length - 1)
			++sum;
		if(sum >= 10) {
			if(i == 0)
				isOverflow = true;
			else {
				sum -= 10;
				carry = 1;
				str[i] = '0' + sum;
			}

			printf("\n");
		}
		else {
			str[i] = '0' + sum;
			break;
		}
	}

	return isOverflow;
}

void Print1ToMax(char* str, int n) {
	if(n <= 0)
		return;
	while(!Increment(str, n))
		PrintNumber(str);
}

void main() {
	int n = 3;
	char str[n+1];
	memset(str, '0', n);
	str[n] = '\0';
	Print1ToMax(str, n);
	
}
