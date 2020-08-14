#include<stdio.h>

void main() {
	int a = 6;
	int b = 9;

	int x = a;
	int y = b;
	
	int d = 0;

	while(((a & 1) == 0) && ((b & 1) == 0)) {
		a >>= 1;
		b >>= 1;
		d++;
	}

	int g = a;

	while( a != b) {
		if(a == 1 || b == 1) {
			g = 1;
			break;
		}
		else if((a & 1) != 1)
			a >>= 1;
		else if((b & 1 ) != 1)
			b >>= 1;
		else if(a > b)
			a = (a - b) >> 1;
		else
			b = (b - a) >> 1;
		
		g = a;
	}

	int gcd = g * (1 << d);
	printf("GCD of %d & %d is %d\n", x, y, gcd); 
}
