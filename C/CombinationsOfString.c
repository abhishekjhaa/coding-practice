/*Find the no of combinations for a given string.
For example, if given string is "ab". Combinations are ' ', a, b, ab*/

#include<stdio.h>
#include<math.h>

void main() {
	char str[] = "abcd";
	printf("Input String is : %s\n", str);
	int length = sizeof(str)/sizeof(char) - 1; // -1 beacuse '\0' is also appended in the array
	int noOfCombinations = pow(2, length); // Compile with -lm i.e., cc CombinationOfString.c -lm
	int i;
	printf("Combinations are: ");
	for(i = 0; i < noOfCombinations; i++) {
		int shift = 0;
		while(shift < length) {
			if(i & (1 << shift))
				printf("%c", str[shift]);
			shift++;
		}
		
		printf(", ");
	}

	printf("\n");
}
