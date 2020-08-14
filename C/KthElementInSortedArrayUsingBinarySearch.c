#include<stdio.h>

int BinarySearch(int* array, int length, int element) {
	int l = 0;
	int u = length - 1;
	int result = -1;
	while(l <= u) {
		int m = l + (u - l) / 2;
//		printf("m = %d & array[m] = %d\n", m , array[m]);
		if(array[m] == element) {
			if(array[m-1] < array[m])
				return m;
			result = m;
			u = m - 1;
		}
		else if(array[m] > element)
			u = m - 1;
		else
			l = m + 1;
	}

	return result;
}

// Need to find 1st Occurence of K in the array.
void main() {
	int array[] = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
	int length = 10;
	int element = 108;
	int index = BinarySearch(array, length, element);
	if(index >= 0)
		printf("For element %d First Occuring Index is : %d\n", element, index);
	else
		printf("Element %d doesn't exist in the array\n", element);
	
	element = 285;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Occuring Index is : %d\n", element, index);
        else
                printf("Element %d doesn't exist in the array\n", element);
	
	element = 401;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Occuring Index is : %d\n", element, index);
        else
                printf("Element %d doesn't exist in the array\n", element);

	element = -14;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Occuring Index is : %d\n", element, index);
        else
                printf("Element %d doesn't exist in the array\n", element);

        element = 78;
        index = BinarySearch(array, length, element);
        if(index >= 0)
                printf("For element %d First Occuring Index is : %d\n", element, index);
        else
                printf("Element %d doesn't exist in the array\n", element);

}
