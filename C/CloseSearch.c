#include<stdio.h>
#include<math.h>

// abs(Array[i] - Array[i+1]) <= 1
void main() {
	int array[] = {-1,0,0,1,2,2,1,2,3,4};
	int length = 10;
	int k = 2;
	int i = 0;
	printf("k = %d occurs at : ", k);
	int count = 0;
	while(i < length) {
		if(array[i] == k)
			printf("%d, ", i++);
		else {
			int leap = abs(k - array[i]);
			i += leap;
		}
		count++;
	}
	printf("\nNo of times it iterated : %d\n", count);
}
