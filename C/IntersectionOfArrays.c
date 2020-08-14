#include<stdio.h>

void main() {
	int arr1[] = {1,4,7,10,13,21};
	int arr2[] = {1,3,5,6,7,9,11,15,21};

	int len1 = 6;
	int len2 = 9;

	int i = 0;
	int j = 0;
	
	while(i < len1 && j < len2) {
		if(arr1[i] == arr2[j]) {
			printf("%d, ", arr1[i]);
			i++;
			j++;
		}
		
		if(arr1[i] > arr2[j])
			j++;
		else
			i++;
	}

	printf("\n");
}
