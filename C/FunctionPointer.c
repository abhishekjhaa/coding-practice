#include<stdio.h>

typedef unsigned int (*fun)(unsigned int);

unsigned int sumZero(unsigned int n) {
	return 0;
} 

unsigned int sum(unsigned int n) {
	static fun arr[2] = {sumZero, sum};
	return n + arr[!!(n)](n-1);

}

void main () {
	int n = 50;
	int result = sum(n);
	printf("Sum of 1 to %d is %d\n", n, result);
}
