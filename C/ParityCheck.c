#include<stdio.h>

void main() {
	int x = 7;
	int y = x;
	int count = 0;
	int i = 0;
	while(i < sizeof(int)*8 && x > 0) {
		//printf("%d\n", (x & (~(x - 1))));
		if((x & (~(x-1))) > 0) {
			count++;
			x = x >> (x & (~(x - 1)));
		}
		else
			x >>= 1;
		i++;
		//printf("i : %d x : %d\n", i, x);
	}
	
	printf("%d has %s\n", y, count%2 == 0 ? "Even Parity" : "Odd Parity");
}
