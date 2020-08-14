#include<stdio.h>
#include<malloc.h>

int LeftShiftTheNumber(int number) {
        if(number < 0)
                number *= -1;
        int count = 0;
        while(number) {
                if(number & 1 == 1)
                        count++;
                number >>= 1;
        }
	
	return count;
}

int RightShiftOneDoAnd(int number) {
	unsigned int flag = 1;
	int count = 0;
        if(number < 0)
                number *= -1;
	while(flag) {
		if(number & flag)
			count++;
		flag = flag << 1;
	}

	return count;
}

int UsingSubstraction(int n) {
 	int count = 0;
        if(n < 0)
                n *= -1;
 	while (n) {
 		++ count;
 		n = (n - 1) & n;
 	}

 	return count;
}

void main() {
	int number = -9;

	int count = LeftShiftTheNumber(number);
	printf("Using LeftShift  : No of 1s in %d is %d \n", number, count);
	
	count = RightShiftOneDoAnd(number);
        printf("Using RightShift : No of 1s in %d is %d \n", number, count);

	count = UsingSubstraction(number);
        printf("Using Substraction: No of 1s in %d is %d \n", number, count);

}
