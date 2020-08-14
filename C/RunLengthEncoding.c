#include<stdio.h>
#include<malloc.h>

char* DoEncoding(char* str) {
	int i = 0, count = 0, j = 0;
	char* encodedStr = malloc(sizeof(char));
	while(str[i] != '\0') {
		char temp = str[i];
		while(temp == str[i]) {
			i++;
			count++;
		}
		encodedStr = realloc(encodedStr, (j+2)*sizeof(char));
		encodedStr[j++] = count + '0';
               	encodedStr[j++] = temp;

		count = 0;
	}
	
	return encodedStr;
}

char* Decode(char* encodedStr) {
	int i = 0, j = 0, count = 0;
	char* str = malloc(sizeof(char));
	while(encodedStr[i] != '\0') {
		count = encodedStr[i++] - '0';
		str = realloc(str, count*sizeof(char));
		while(count > 0) {
			str[j++] = encodedStr[i];
			count--;
		}
	
		i++;
	}
	
	return str;
}
void main() {
	char* str = "aaaabbceee";
	printf("Original String : %s\n", str);
	char* encodedStr = DoEncoding(str);
	printf("Encoded String  : %s\n", encodedStr);
	char* decodedStr =Decode(encodedStr);
	printf("Decoded String  : %s\n", decodedStr);
}
