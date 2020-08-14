#include<stdio.h>
#include<stdbool.h>

int StrToInt(char* string) {
 	int number = 0;
	bool posOrNeg =  false;
	if((*string) == '-')
	{	
		posOrNeg = true;
		++string;
	}

 	while(*string != 0) {
		if(*string - '0' > 9 || *string - '0' < 0)
		{
			return 0;
		}

 		number = number * 10 + *string - '0';
 		++string;
 	}
	
	if(posOrNeg)
	{
		number *= -1;
	}

 	return number;
}

void main()
{
	char str[255];
	scanf("%s", str);
	if(str != NULL)
	{
		int num = StrToInt(str);
		if(num == 0)
		{
			printf("%s", "Enter a Valid String");
		}
		else
		{
			printf("%d \n", num);
		}
	}
	else
	{
		printf("%s \n", "Enter a Valid number");
	}
}
