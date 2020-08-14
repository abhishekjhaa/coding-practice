#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*
Because the array str is a local variable, it is deallocated automatically when the execution flow leaves the function allocateMemory. Therefore, the returned 
memory to pString in the function test is actually invalid, and its content is 
somewhat random.
*/

char* allocateMemory() {
	char str[20] = "Hello world.";
	return str;
}

/*
The parameter pString in the function allocateMemory is a pointer, and the 
string content it points to can be modified. However, the memory address it 
owns cannot be changed when the function allocateMemory returns. Since the 
input parameter pString of allocateMemory in the function test is NULL, it 
remains NULL after the execution of allocateMemory, and it causes the program 
to crash when the NULL address is accessed in test. 
*/
void allocateMemory1(char* pString, int length) {
	pString = malloc(length*sizeof(char));
}

/*
To fix the above problem, the first parameter of allocateMemory should be
modified as char** pString. 
*/
void allocateMemory2(char** pString, int length) {
        *pString = malloc(length*sizeof(char));
}

void main() {
	char* pString = allocateMemory();
	printf("pString is %s.\n", pString);

        char* pString2 = NULL;
        allocateMemory2(&pString2, 20); // Passing the reference of pString2
        strcpy(pString2, "Hello world.");
        printf("pString2 is %s.\n", pString2);
	
	char* pString1 = NULL;
 	allocateMemory1(pString1, 20);
 	strcpy(pString1, "Hello world.");
	printf("pString1 is %s.\n", pString1);
}
