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

void Print1ToMaxOfNDigitsCore(char* number, int length, int index) {
 	if(index == length - 1) {
 		PrintNumber(number);
 		return;
 	}

	int i;
 	for(i = 0; i < 10; ++i) {
 		number[index + 1] = i + '0';
		//printf("i is %d index is %d for %s -> ", i, index, number);
 		Print1ToMaxOfNDigitsCore(number, length, index + 1);
 	}

	printf("\n");
}

void Print1ToMax(char* str, int n) {
	if(n <= 0)
		return;
	Print1ToMaxOfNDigitsCore(str, n, -1);
}

void main() {
	int n = 2;
	char str[n+1];
	memset(str, '0', (n+1)*sizeof(char));
	str[n] = '\0';
	Print1ToMax(str, n);
	
}
