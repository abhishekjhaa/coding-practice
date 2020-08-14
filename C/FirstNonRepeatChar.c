#include<stdio.h>
#include<string.h>

void main() {
	char* str = "google";
	char* temp = str;
	int array[256];
	memset(array, -1, sizeof(array));
	
	while(*str != '\0') {
		if(array[*str] == -1)
			array[*str] = 1;
		else
			array[*str] += 1;
		str++;
	}
	
	str = temp;
	
	while(*str != '\0') {
		if(array[*str] == 1) {
			printf("%c is the first non repeating character of word %s\n", *str, temp);
			return;
		}
		str++;
	}
}
