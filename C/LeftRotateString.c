#include<stdio.h>

void Reverse(char* newStr, int i, int j) {
        while(j >= i) {
                char ctemp = newStr[i];
                newStr[i++] = newStr[j];
                newStr[j--] = ctemp;
        }
}
void main() {
	char str[] = "abcdefg";
	int leftRotateBy = 2;
	int length = sizeof(str)/sizeof(char) - 1; // It also counts '\0' thats why we substracted 1
	printf("%s\n", str);
	Reverse(str, 0, length - 1); // First Reverse the whole string.
	Reverse(str, 0, (length - 1) - leftRotateBy); // Reverse the 1st partition
	Reverse(str, length - leftRotateBy, length - 1); // Reverse the 2nd partition
        printf("Left rotated original string by %d:  %s\n", leftRotateBy, str);
}
