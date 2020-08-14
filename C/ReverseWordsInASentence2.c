#include<stdio.h>
#include<malloc.h>

void Swap(char* str, int i , int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void main() {
	char* str = malloc(20*sizeof(char));
	char* filler = "I am a Student";
	printf("%s\n", filler);
	int start = 0, end, length = 0;
	while(filler[length] != '\0') {
		str[length] = filler[length];
		length++;
	}

	end = length - 1;
	while(start < end)
		Swap(str, start++, end--);

	start = 0, end = 0;
	int temp = 0;
	while(length > temp) {
		while(str[end] != ' ' && str[end] != '\0')
			end++;

		temp = end;
		end--;
		while(start < end)
			Swap(str, start++, end--);

		start = temp + 1;
		end = temp + 1;
	}

	printf("%s\n", str);
}
