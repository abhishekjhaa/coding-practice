/*Given an infinite number of quarters (25 cents), dimes (1O cents), nickels (5 cents) 
and pennies (1 cent), write code to calculate the number of ways of representing n cents. */


/*We can imagine that our N cents are equal to 1*25 + x1 or 2*25 + x2 or 3*25 + x3 and so on, 
then x1 will be equal to 1*10 + y1 or 2*10 + y2 or 3*10 an so on. 
By reducing our amount by i * coin_value we can get to the base case which will be to 
calculate number of ways representing Z cents using only pennies which is equal to 1. 
Because there is only one way to represent any amount of money using only pennies.*/

#include<stdio.h>

#define N 100

int UsingRecursion(int n, int* coins, int index) {
	if(index <= 0)
		return coins[0]; // i.e., return 1
	
	int ways = 0, i;
	for(i = 0; i*coins[index] <= n; i++) {
		ways += UsingRecursion(n - (i * coins[index]), coins, index - 1);
	}

	return ways;
}

void main() {
	int coins[] = {1, 5, 10, 25};
	int noOfCoins = 4;
	int result = UsingRecursion(N, coins, noOfCoins - 1);
	printf("%d\n", result);
}	
