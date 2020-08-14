#include<stdio.h>

/*
The result of 3+4 is 7, and the square of 7 is 49. However, 49 is not the 
result of SQUARE(3+4) . Macros are substituted by the preprocessor, so 
SQUARE(3+4)  becomes 3+4*3+4, which is actually 19. In order to make the 
result as expected, the macro should be modified to #define SQUARE(x) ((x)*(x)) 
*/

#define SQUARE(x) (x*x)
#define SQUARE1(x) ((x)*(x))

void main() {
	printf("Square of (3+4) is %d.\n", SQUARE(3+4));
	printf("Square1 of (3+4) is %d.\n", SQUARE1(3+4));
	
	int x = 5;
 	int y = SQUARE1(x++);
 	printf("Result of x is %d, y is %d.\n", x, y);
}
