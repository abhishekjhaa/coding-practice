#include<stdio.h>

int main()
{
	int myArray[10];
	printf("myArray Starting Address = %p\n", myArray);
	printf("&myArray Starting Address = %p\n", &myArray);
	printf("Both Address Should be same \n");
	printf("myArray Garbage value at index 0 = %d \n", myArray[0]);
	
	myArray[0] = 1;
	printf("myArray Initialized value at index 0 = %d \n", myArray[0]);
	
	printf("myArray Starting Address = %p\n", (void *) myArray);
	printf("&myArray Starting Address = %p\n", (void *) &myArray);		
}
