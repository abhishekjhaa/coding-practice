#include<stdio.h>

int UsingRecursion(int combination[34][18], int n, int k) {
	if(k == 0 || n == k)
		return 1;
	else
		if(combination[n - 1][k] != -1 && combination[n - 1][k - 1] != -1)
                        return combination[n - 1][k] + combination[n - 1][k - 1];
		else if (combination[n - 1][k] != -1)
			return combination[n - 1][k] + UsingRecursion(combination, n - 1, k - 1);
		else if(combination[n - 1][k - 1] != -1)
			return UsingRecursion(combination, n - 1, k) + combination[n - 1][k - 1];
		else
			return UsingRecursion(combination, n - 1, k) + UsingRecursion(combination, n - 1, k - 1);
		
}

void main() {
	int n = 33;
	int k = 17;
	int combination[n + 1][k + 1];
	int i, j;
	for(i = 0; i <= n; i++)
		combination[i][0] = 1;
	for(i = 1; i <= k; i++)
		combination[i][i] = 1;

	for(i = 2; i <= n; i++)
		for(j = 1; j < i && j <= k; j++) //Imp Step
			combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];

	printf("n = %d k = %d nCk = %d\n", n, k, combination[n][k]);
	for(i = 0; i <= n; i++)
        	for(j = 0; j <= k; j++)
                	combination[i][j] = -1;
	int result = UsingRecursion(combination, n, k);
	printf("Using Recursion %d\n", result);
}
