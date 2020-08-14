#include<stdio.h>
#include<string.h>

// All the characters if letter must be consumed by magazine.
void main() {
	int characterSize = 256;
	char* letter = "I am thrilled to be here.";
	char* magazine = "here to be in this moment, I am thrilled.";
	int hashMap[characterSize];
	memset(hashMap, 0, 256);

	int count = 0;
        while(count < characterSize) {
                hashMap[count] = 0;
                count++;
        }

	count = 0;
	while(letter[count] != '\0') {
		if(letter[count] != ' ')
			hashMap[letter[count]] += 1;
		count++;
	}
	
	count = 0;
	while(magazine[count] != '\0') {
                if(hashMap[magazine[count]] > 0)
			hashMap[magazine[count]] -= 1;
                count++;
        }
	
	count = 0;
	int flag = 1;
	while(count < characterSize) {
		if(hashMap[count] != 0) {
			printf("Character is not consumed by Magazine : '%c' - %d times\n", count, hashMap[count]);
			flag = 0;
			break;
		}
		
		count++;
	}

	if(flag == 1)
		printf("Magazine can be written using letter\n");
	else
		printf("Magazine can't be written using letter\n");
}
