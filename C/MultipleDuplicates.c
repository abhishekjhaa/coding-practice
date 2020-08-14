#include<stdio.h>

#define N 7

void PrintArray(int* array) {
	int i;
        for(i = 0; i < N; i++)
                printf("%d, ", array[i]);
        printf("\n");
}

int main() { 
	// Constraint : largest number in the array won't be greater that tha size of array.
	int dupArray[N] = {1,5,2,6,4,3,4};
	PrintArray(dupArray);
	int i;
	for(i = 0; i < 7 ;i++ )
	{	
		printf("For index = %d\n", i);
		while(dupArray[i] !=  i)
		{
			if(dupArray[i] == dupArray[dupArray[i]])
			{	
				printf("\tDuplicate Found %d \n", dupArray[i]);
				PrintArray(dupArray);
				return;
			}
			else
			{	
				printf("\tSwapped %d %d \n", dupArray[i], dupArray[dupArray[i]]);	
				int temp = dupArray[i];
				dupArray[i] = dupArray[temp];
				dupArray[temp] = temp;
				PrintArray(dupArray);
			}
		}
	}

}
