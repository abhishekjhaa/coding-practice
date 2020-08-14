/*An array A contains all the integers from 0 to n, except for one number which is 
missing. In this problem, we cannot access an entire integer in A with a single 
operation. The elements of A are represented in binary, and the only operation 
we can use to access them is "fetch the jth bit of A[i]," which takes constant 
time. Write code to find the missing integer. Can you do it in O(n) time? */

// Since x^x = 0; so if we xor each number twice we should get zero. 
//but if a number if missing we'll get that number.
// List of numbers 0,1,3
// Xor of all the numbers twice, between 0 and 3 : (1^1)^(2^2)^(3^3) is equal to 0
// Since 2 is missing from the list, then
// (1^1)^(2)^(3^3) == (1^2^3) ^(1^3) is equals to 2. Hence we get our missing number.
//                  = (allXor)^(missingNumber)

/*We can do xor of all the numbers from 0 to n and save the resulting number. 
Now we'll xor for every bit of given list and do the final xor with the corresponding bit of the saved number. 
The final result will give us the missing number. But solution might not be O(n).*/

#include<stdio.h>

int Fetch(int digit, int shift) {
	return (digit & (1 << shift));
}

void main() {
	int n = 200, i, j = 0;
	int array[n];
	for(i = 0; i <= n; i++)
		if(i == 113) { // Missing Number
		}
		else
			array[j++] = i;

	int maskedBit, missingNumber = 0, xorAll = 0;
	
	for(i = 0; i <= n; i++)
		xorAll ^= i; // Xor of all the numbers from 0 to n
	
	for(j = 0; j < 8*sizeof(n); j++) {
		maskedBit = 0;
		for(i = 0; i < n; i++) {
			maskedBit ^= Fetch(array[i], j);
		}
		
		missingNumber |= maskedBit;	//For each bit position we are saving the bit.				
	}

	printf("%d\n", xorAll^missingNumber);	// Runtime O(kn); where k is size of int in bits.
}
