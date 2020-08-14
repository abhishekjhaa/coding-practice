#include<stdio.h>
#include<string.h>
#include<malloc.h>
void main() {
        char* charsToBeDeleted = "aeiou";
	char* tempC = charsToBeDeleted;
        char* str = "We are students";
	char* slow = malloc(sizeof(str));
	char* fast = str;
	char* temp = slow;
        int array[256];
        memset(array, -1, sizeof(array));

        while(*charsToBeDeleted != '\0') {
                if(array[*charsToBeDeleted] == -1)
                        array[*charsToBeDeleted] = 1;
                charsToBeDeleted++;
        }
	
        while(*fast != '\0') {
                if(array[*fast] == -1) {
                        *slow = *fast;
			slow++;
		}
                fast++;
        }
	*slow = '\0'; 
	printf("Characters to be deleted : %s\nfrom : %s\nAnd result is : %s\n", tempC, str, temp);
}

