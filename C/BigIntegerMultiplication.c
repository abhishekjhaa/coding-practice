#include<stdio.h>
#include<malloc.h>
#include<string.h>

void Multiply(char* num1, int len1, char* num2, int len2) {
	int k = len1 + len2 - 1;
	char* result = malloc((k+1)*sizeof(char));
	memset(result, '0', k+1);
	int i, j = len2 - 1, carry;
	while(j >= 0) {
		i = len1 - 1;
		carry = 0;
		while(i >= 0) {
			int temp1 = num1[i--] - '0';
			int temp2 = num2[j] - '0';
			int temp3 = result[k] - '0';
			result[k--]  = ((temp3 + (temp1 * temp2 + carry)) % 10) + '0';
			carry = (temp3 + (temp1 * temp2 + carry)) / 10;
		}

	        if(carry > 0)
        	        result[k] = carry + '0';

		k += len1 - 1;
		j--;
	}

	printf("%s * %s = %s\n",num1, num2, result);
}

void main() {
	char* num1 = "1234567899876543";
	int len1 = 16;
	char* num2 = "9876543211234567";
	int len2 = 16;
	Multiply(num1, len1, num2, len2);
}
