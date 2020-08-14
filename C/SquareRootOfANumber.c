#include<stdio.h>

int Compare(double p, double q) {
	double diff = p - q;
	if(diff < -1*0.000001 )
		return -1;
	else if(diff > 0.000001)
		return 1;
	else
		return 0;
}

double SquareRoot(double x) {
	double l, u, m;
	if(x > 1) {
		l = 1.0;
		u = x;
	}
	else if(x > 0 && x < 1) {
		l = 0.0;
		u = x;
	}
	else if( x == 1.0 || x == 0.0)
		return x;
	else {
		printf("Negative Numbers are not allowed\n");
		return -1;
	}

	while(l < u) {
		m = l + (u - l)/2;
		if(Compare(m*m, x) == 0)
			return m;
		else if(Compare(m*m, x) == 1)
			u = m;
		else
			l = m;
	}

	return -1;
}

void main() {
	double number = 1024;
	double result = SquareRoot(number);
	if(result > -1)
		printf("Square Root of %f is %f\n", number, result);
	else
		printf("No Square Root Found for %f\n", number);
}
