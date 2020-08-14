/*Remove identical elements from a sorted integer array*/
#include<stdio.h>

void main() {
	int a[] = {1, 1, 2, 2, 2, 3, 4, 5, 6, 6};
	int length = sizeof(a)/sizeof(a[0]);
	int i = 0, j = 0;
	while(j < length) {
		if(a[i] == a[j])
			j++;
		else {
			i++;
			a[i] = a[j];
			j++;
		}
	}

	a[i + 1] = NULL;	
	for(i = 0; a[i] != NULL; i++)
		printf("%d, ", a[i]);
	printf("\nSize of array = %d\n", i);
}

