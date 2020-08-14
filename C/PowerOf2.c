#include<stdio.h>
#include<math.h>

void main() {
	int n = 16;
	if(n != 0 && ((n - 1) & n) == 0)
		printf("%d is a power of 2 \n", n);
	else
		printf("%d is not a power of 2 \n", n);
}
