#include<stdio.h>
#include<malloc.h>
void main() {
	char* str = "I am a Student";
	char* temp = str;
	char* newStr = malloc(sizeof(str));
	char* tempC = newStr;
	int count = 0;
	while(*temp != '\0') {
		count++;
		temp++;
	}
	
	int i = 0;
	int j = count - 1;
	printf("%s\n", str);
	while(j > i) {
		newStr[i] = str[j];
		newStr[j--] = str[i++];
	}
	printf("%s\n", newStr);
	i = 0;
	j = 0;
	count = 0;
	while(*tempC != '\0') {
		while(*tempC != ' ' && *tempC != '\0') {
			tempC++;
			count++;
		}

		j = count - 1;
		while(j >= i) {
			char ctemp = newStr[i];
			newStr[i++] = newStr[j];
        	        newStr[j--] = ctemp;
        	}

		i = ++count;
		tempC++;
	}

	printf("%s\n", newStr);
}
