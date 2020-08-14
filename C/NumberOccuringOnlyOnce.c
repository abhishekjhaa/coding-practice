#include<stdio.h>

int XorArray(int array[], int size) {
	if(size < 2)
		return array[0];
	if(size < 1)
		return 0;
	int count  = 1;
        int xor = (array[count - 1]) ^ (array[count]);
        count++;
        while(array[count] != 0 && count < size)
                xor = xor ^ (array[count++]);
	return xor;
}

void AnotherWayUsingConstantSpace(int* array, int flag, int length) {
	int count = 0;
	int h = 0;
	while(count < length) {
		if(flag & array[count])
			h ^= array[count];
		count++;
	}

	printf("Using Constant Space Numbers are %d & %d\n", h, h^flag);
}

void main() {
	int array[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int length = 8;
	int xor = XorArray(array, length);
	int flag = 1;
	while(flag & xor != 1)
		flag <<= 1;

	int temp1[length];
	int temp2[length];
	int count = 0;
	int i = 0;
	int j = 0;	
	while(array[count] && count < length)
		if((array[count] & flag) > 0)
			temp1[i++] = array[count++];
		else
			temp2[j++] = array[count++];
	
	int xor1 = XorArray(temp1, i);
	int xor2 = XorArray(temp2, j);
	printf("Numbers occuring only once in the array are %d & %d \n", xor1, xor2);

	AnotherWayUsingConstantSpace(array, flag, length);
}
