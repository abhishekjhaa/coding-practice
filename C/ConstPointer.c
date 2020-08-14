#include<stdio.h>

void main()
{
	//// Constant Reference
	int var0 = 0;
	const int &ptr1 = var0;
	ptr1 = 8; // Error
	var0 = 6; // OK

	//// Constant Pointer
	int var1 = 1;
	int var2 = 0;
	int *const ptr2 = &var1;
	ptr2 = &var2; // Error

	//// Pointer to Constant
	int const * ptr3 = &var2;
	*ptr3 = 4; // Error

	//// Constant Pointer to a Constant
	int var3 = 0;
	int var4 = 0;
	const int * const ptr4 = &var3;
	*ptr4 = 1;     // Error
 	ptr4 = &var4; // Error
}
