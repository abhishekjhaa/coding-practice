#include<stdio.h>

int sizeOfArray(int a[10])
{
	return sizeof(a);
}

void main() {
	int myArray[10];
	
	/* Each int in this array is 4 bytes, so the
	size of this array is 4 * 10 = 40 */
	
	printf("sizeof(myArray) = %d\n",sizeof(myArray)); // 40
	
	/* However .. the function does not receive the array,
	it receives a pointer to an int, which is 4 bytes */
	
	printf("sizeOfArray(myArray) = %d\n",sizeOfArray(myArray)); // 4
}
