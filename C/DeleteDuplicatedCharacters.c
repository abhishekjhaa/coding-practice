#include<stdio.h>
#include<string.h>
#include<malloc.h>

void main() {
        char* str = "google";
        char* temp = (char*)malloc(sizeof(str));;
	char* newStr = temp;
        int array[256];
        memset(array, -1, sizeof(array));

        while(*str != '\0') {
                if(array[*str] == -1) {
                        array[*str] = 1;
			*temp = *str;
			temp++;
		}
                str++;
        }
	
	*temp = '\0';

        printf("%s\n", newStr);
}
