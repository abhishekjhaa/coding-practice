#include<stdio.h>

/* This code generates a compiler warning
 expected 'int *' but argument is of type 'int (*)[10]'
*/

void handleArray(int * theArray) {
 	// do something with the array pointer…
 	printf("Handled it Sucessfully \n");
}

void main()
{
	int myArray[10];
	handleArray(&myArray);
}
