#include<stdio.h>
#include<string.h>

#define NUMBER_LENGTH 20

int IsPalindrome(const char* const string) {
 	int palindrome = 1;
 	if(string != NULL) {
 		int length = strlen(string);
 		int half = length >> 1;
		int i;
 		for(i = 0; i < half; ++ i) {
 			if(string[i] != string[length - 1 - i]) {
 				palindrome = 0;
				printf("Not Palindrome "); 	
				break;
 			}
		}

	}

	return palindrome;
}

/* It returns 1 when number is palindrome, otherwise returns 0. */
int IsPalindrome_solution1(unsigned int number) {
 	char string[NUMBER_LENGTH];
 	sprintf(string, "%d", number);
	printf("Number Converted to string : %s ", string);
 	return IsPalindrome(string);
}

/* It returns 1 when number is palindrome, otherwise returns 0. */
int IsPalindrome_solution2(unsigned int number) {
 	int reversed = 0;
 	int copy = number;
 	while(number != 0) {
 		reversed = reversed * 10 + number % 10;
 		number /= 10;
 	}

 	return (reversed == copy) ? 1 : 0;
}

void main() {
	printf("%d \n", IsPalindrome_solution1(151));
	printf("%d \n", IsPalindrome_solution1(1551));
	printf("%d \n", IsPalindrome_solution1(1231));

	printf("%d \n", IsPalindrome_solution2(151));
        printf("%d \n", IsPalindrome_solution2(1551));
        printf("%d \n", IsPalindrome_solution2(1231));

}
