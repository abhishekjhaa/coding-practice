#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<malloc.h>

int Minimum(int a, int b, int c, int d) {
	int min =  a > b ? (b > c ? c : b) : (a > c ? c : a);
	return min > d ? d : min;
}

int CountMinimumCoins(int coin[], int noOfCoins, int sum) {
	if(sum < 0)
		return INT_MAX;
	int i;
	for(i = 0; i < noOfCoins; i++)
		if(sum -  coin[i] == 0)
			return 1;

	return  Minimum(CountMinimumCoins(coin, noOfCoins, sum - coin[0]),
			CountMinimumCoins(coin, noOfCoins, sum - coin[1]),
			CountMinimumCoins(coin, noOfCoins, sum - coin[2]),
			CountMinimumCoins(coin, noOfCoins, sum - coin[3])) + 1;
}

int CountUsingIteration(int coins[], int sum) {
	int row = 0;
	int col = sum;
	while(coins[row])
		row++;
	int counts[col+1];
	counts[0] = 0;
	
	int i, j;
	for(i = 1; i <= col; i++) {
		int max = INT_MAX;
		for(j = 0; j < row; j++) {
			if((i - coins[j]) >= 0 && max > counts[i - coins[j]]) {
				max = counts[i - coins[j]];	
				printf("Max is %d for Coin No. %d  Column is : %d \n", max, coins[j], i);
			}
		}
		
		if(max < INT_MAX)
			counts[i] = max + 1;
		else
			counts[i] = INT_MAX;
	}
	
	return counts[col];
}

void main() {
	int coins[] = {1, 3, 9, 10};
	int sum = 6;
	int result = CountMinimumCoins(coins, 4, sum);
	printf("Using  Recursion : Minimum No of Coins required to get a sum of %d is %d \n", sum, result);
	result = CountUsingIteration(coins, sum);
        printf("Using  Iteration : Minimum No of Coins required to get a sum of %d is %d \n", sum, result);
 
}
