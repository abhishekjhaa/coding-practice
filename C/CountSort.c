#include<stdio.h>
#include<string.h>
int main()
{
        int size,j,i;
        printf("Enter the size of array :");
        scanf("%d",&size); 
        int distinctIntegersInArray = 100; // In place of 100 you can take any number you want
	int dup[size],f[distinctIntegersInArray]; // In place of 'f' give some meaningful array name
	memset(f, 0, distinctIntegersInArray*sizeof(int)); // initialize the values to 0 in all the index of f
        for(i = 0; i < size; i++) {
		dup[i] = rand() % 100; //Fill array with any number between 0 & 99.
		f[dup[i]]++; // f[dup[i]] = f[dup[i]] + 1;

        }
		
	j=0;
	for(i = 0; i < distinctIntegersInArray; i++) {
		if(f[i] != 0)
			while(f[i]--) {
				dup[j] = i; // Overrite the original array
				printf("%d, ", dup[j++]);
			}
	}      
	
	printf("\n");
}
