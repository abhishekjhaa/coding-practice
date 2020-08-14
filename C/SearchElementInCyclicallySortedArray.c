#include<stdio.h>

int BinarySearch(int* array, int length, int k) {
        int l = 0;
        int u = length - 1;
        while(l < u) {
                int m = l + (u - l)/2;
//              printf("l = %d & u = %d & m = %d & array[m] = %d\n", l, u, m, array[m]);
		if(array[m] == k)
			return m;
		if(array[l] == k)
			return l;
		if(array[u] == k)
			return u;

		if(u - l == 2)
			return -1;

                if(array[m] > array[l] && k < array[m] && k > array[l])
			u = m - 1;
		else if(array[m] < array[u] && k > array[m] && k < array[u])
                        l = m + 1;

		else if(array[m] > k && array[u] < array[m])
			l = m + 1;
		else if(array[m] < k && array[l] > array[m])
			u = m - 1;
		
		else if(array[m] < k)
                        l = m + 1;
		else if(array[m] > k)
                        u = m - 1;
		
        }

	return -1;
}


//Find the starting Point
void main() {
	int array[] = {16, 32, 78, 98, 103, 203, 220, 6, 7, 8};
	//int array[] = {4, 5, 1, 2, 3};
	int length = 10, i;
	for(i = 0; i < length; i++) {
		int k = array[i];
		int index = BinarySearch(array, length, k);

		if(index >= 0)
			printf("k = %d at index %d\n", k, index);
		else
			printf("No Element found\n");
	}
}
