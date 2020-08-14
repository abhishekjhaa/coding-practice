#include<stdio.h>
#include<string.h>
#include<malloc.h>
void main() {
        char* word1 = "silent";
	char* temp1 = word1;
        char* word2 = "listen";
	char* temp2 = word2;
        int array[256];
        memset(array, -1, sizeof(array));

        while(*word1 != '\0') {
                if(array[*word1] == -1)
                        array[*word1] = 1;
		else
			array[*word1] += 1;
                word1++;
        }

        while(*word2 != '\0') {
                if(array[*word2] > 0)
                        array[*word2] -= 1;
		else {
			printf("%s & %s are not Anagrams\n", temp1, temp2);
			return;
		}

                word2++;
        }

        printf("%s & %s are Anagrams\n", temp1, temp2);
}

