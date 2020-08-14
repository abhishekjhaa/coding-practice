#include<stdio.h>
#include<math.h>

void main() {
	char string[] = {'a', 'b', 'c'};
	int length = 3;
	int totalSets = pow(2, 3);
	int i;
	printf("PowerSet/Combinations of %s:\n", string);
	for(i = 1; i < totalSets; i++) {
		int x = i;
		int j;
		for(j = 0; j < length; j++ ) {
			if(x & 1 == 1)
				printf("%c", string[j]);
			x >>= 1;
		}
		if(i < totalSets - 1)
			printf(", ");
	}

	printf("\n");
}
