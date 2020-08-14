#include<stdio.h>
#include<string.h>

void DoTheSum(char* num1, int len1, char* num2, int len2, char* sum, int len3) {
	int i;
	int carry = 0;
	int tempSum = 0;
	for(i = 1; i < len3; i++) {
		if((len1 - i) >= 0 && (len2 - i) >= 0)
			tempSum = (num1[len1 - i] - '0') + (num2[len2 - i] - '0') + carry;
		else if(len1 - i >= 0)
                        tempSum = (num1[len1 - i] - '0') + carry;
                else if(len2 - i >= 0)
                        tempSum = (num2[len2 - i] - '0') + carry;
	
		sum[len3 - i] = (tempSum%10) + '0';
		carry = tempSum/10;
	}

	if(carry > 0) {
		sum[len3 - i] = carry + '0';
	}
}

void main() {
	char* number1 = "1";
	char* number2 = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
	int count1 = 0;	
	while(number1[count1])
		count1++;
	int count2 = 0;
	while(number2[count2])
                count2++;
	printf("Count1 %d Count2 %d \n", count1, count2);
	int n = count2 > count1 ? count2 : count1;
	char sum[n+1];
	memset(sum, '0', n+1);
	DoTheSum(number1, count1,  number2, count2, sum, n+1);
	printf("Sum of \n%s & \n%s is:\n%s\n", number1, number2, sum);
}
