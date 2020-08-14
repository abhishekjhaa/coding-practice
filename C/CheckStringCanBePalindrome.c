#include<stdio.h>
#include<string.h>

void main() {
	int characterSize = 256;
	char* str = "edified";
	int hashMap[characterSize];
	memset(hashMap, 0, 256);

	int count = 0;
	while(str[count] != '\0') {
		hashMap[str[count]] += 1;
		count++;
	}
	
	count = 0;
	int oddCount = 0;
	while(str[count] != '\0') {
                if(hashMap[str[count]] % 2 == 1)
			oddCount++;
                count++;
        }

	if(oddCount <= 1)
		printf("Palindrome can be formed with '%s'\n", str);
	else
		printf("Palindrome can't be formed with '%s'\n", str);
}
