#include<stdio.h>
#include<malloc.h>

void Swap(char* str, int i , int j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
}

void main() {
	// Replace a by dd and remove b with constant storage.
        char* str = malloc(30*sizeof(char));
        char* filler = "abra ka dabra";
        printf("%s\n", filler);
        int start = 0, end, length = 0, countA = 0, countB = 0;
        while(filler[length] != '\0') {
                str[length] = filler[length];
		if(filler[length] == 'a')
			++countA;
		if(filler[length] == 'b')
			++countB;
                length++;
        }
	
	if(countA >= countB)
		end = length - 1 + countA - countB;
	else
		end = length - 1;
	
	length--;

	while(length >= 0) {
		if(str[length] == 'b') {
			length--;
		}
		else if(str[length] == 'a') {
			str[end--] = str[end--] = 'd'; // Interesting.
			length--;
		}
		else {
			str[end--] = str[length--];
		}
	}
	
	printf("%s\n", str);
}
