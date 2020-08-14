#include<stdio.h>

int Divide(int x, int y) {
	if(x < y)
		return 0;
	int power = 0;
	while((1 << power)*y <= x)
		power++;
	int part = 1 << (power - 1);
	return part + Divide((x - part*y), y);

}

void main() {
	int x = 19;
	int y = 5;
	int result = Divide(x, y);
	printf("%d\n", result);
}
