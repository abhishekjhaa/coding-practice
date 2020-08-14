#include<stdio.h>

int GetSize(int data[]) {
	return sizeof(data);
}

int main() {
	int data1[] = {1, 2, 3, 4, 5};
	int size1 = sizeof(data1);
	int* data2 = data1;
 	int size2 = sizeof(data2);
 	int size3 = GetSize(data1);
 	printf(" Size of Array %d \n Size of Pointer to Array %d \n Size of Array passed to another function %d \n", size1, size2, size3);
}
