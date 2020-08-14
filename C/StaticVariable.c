#include<stdio.h>

int hasStatic(int n) {
	printf("Function Called with %d \n", n);
	static int x = 0;
	printf("Value of x before Sum is : %d \n", x);
	x += n;
	printf("Value of x afterr Sum is : %d \n", x);
	return x;
}

void main()
{
	int sum = 0;
 	for(int i = 1; i <= 4; ++i)
	{ 	
		sum += hasStatic(i);
 		printf("Sum is %d \n", sum);
	}
}
