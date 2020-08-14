/*
Write a method to replace all spaces in a string with "%20". You may assume that the 
string has sufficient space at the end of the string to hold the additional characters, 
and that you are given the "true" length ofthe string. (Note: if implementing in Java, 
please use a character array so that you can perform this operation in place.) 
*/

#include<stdio.h>
#include<malloc.h>

void main() {
	char str[] = "I am a good boy";	// If you need to change the string don't declare it as char* declare it as array.
	int countSpaces = 0, i = 0,length;
	while(str[i]) {
		if(str[i] == ' ')
			countSpaces++;
		i++;
	}
	printf("%s\n", str);
	length = i;
	int newLength = length + 2*countSpaces;
	str[newLength--] = '\0';
	i = length - 1;
	while(i >= 0) {
		if(str[i] == ' ') {
			str[newLength--] = '0';
			str[newLength--] = '2';
			str[newLength--] = '%';
		}
		else
			str[newLength--] = str[i] ;
		i--;
	}

	printf("%s\n", str);	
}
