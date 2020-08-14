#include<stdio.h>

int BinarySearch(int* array, int length, int element) {
	int l = 0;
	int u = length - 1;
	int result = -1;
	while(l <= u) {
		int m = l + (u - l) / 2;
//		printf("m = %d & array[m] = %d\n", m , array[m]);
		if(array[m] > element) {
			result = m;
			u = m - 1;
		}
		else
			l = m + 1;
	}

	if(result != -1 && result < length)
		return result;
	else
		return -1;
		
}

void main() {
	int array[] = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
	int length = 10;
	int element = 108;
	int index = BinarySearch(array, length, element);
	if(index >= 0)
		printf("For element %d First Element larger than it, is : %d\n", element, array[index]);
	else
		printf("Element larger than %d doesn't exist in the array\n", element);
	
	element = 101;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Element larger than it, is : %d\n", element, array[index]);
        else
                printf("Element larger than %d doesn't exist in the array\n", element);
	
	element = 401;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Element larger than it, is : %d\n", element, array[index]);
        else
                printf("Element larger than  %d doesn't exist in the array\n", element);

	element = -14;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Element larger than it, is : %d\n", element, array[index]);
        else
                printf("Element larger than  %d doesn't exist in the array\n", element);

        element = 500;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Element larger than it, is : %d\n", element, array[index]);
        else
                printf("Element larger than %d doesn't exist in the array\n", element);

}
