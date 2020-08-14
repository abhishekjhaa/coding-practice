#include<stdio.h>

void main() {
	int x = 92;
	int y = x;
	int i = 0;
	int j = 31;
	while(i < j) {
		if((((x >> i) & 1)) != ((x >> (i+1)) & 1)) {
			x ^= (1 << i | 1 << (i+1));
			break;
		}

		i++;
	}

	printf("Closest Number to %d  which has same number of bits as %d is %d\n", y, y, x);
}
