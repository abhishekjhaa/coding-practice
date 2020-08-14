// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
 
/* Function to swap values at two pointers */
void Swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void Permute(char *str, int startIndex, int endIndex)
{
	if (startIndex == endIndex)
     		printf("%s\n", str);
   	else
   	{
		int i;
       		for (i = startIndex; i <= endIndex; i++)
       		{
			Swap((str + startIndex), (str + i));
        	  	Permute(str, startIndex + 1, endIndex);
        	  	Swap((str + startIndex), (str + i)); //backtrack
       		}
   	}
}
 
/* Driver program to test above functions */
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    Permute(str, 0, n-1);
    return 0;
}
