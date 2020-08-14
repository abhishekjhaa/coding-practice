#include<stdio.h>

#define SIZE 16

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
        return a < b ? a : b;
}

int PickUpCoins(int* coin, int a, int b) {
	if(a > b)
		return 0;
	if(a == b)
		return coin[a];
	if(b - a == 1)
		return Max(coin[a], coin[b]);
	
	return Max((coin[a] + Min(PickUpCoins(coin, a + 1, b - 1), PickUpCoins(coin, a + 2, b))),
		   (coin[b] + Min(PickUpCoins(coin, a + 1, b - 1), PickUpCoins(coin, a, b - 2))));

}

void main() {
	int coins[SIZE] = {25, 5, 10, 5, 10, 5, 10, 25, 1, 25, 1, 25, 1, 25, 5, 10};
	int valueOfCoins = PickUpCoins(coins, 0, SIZE - 1);
	printf("Total Value of Coins Picked By 1st Player To Maximize His Profit = %d\n", valueOfCoins);
}
