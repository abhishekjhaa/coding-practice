#include<stdio.h>
#include<malloc.h>

void ShortMethod(unsigned int x) {
	int i = 0;
	int j = 31;
	while(i < j) {
		if(((x >> i) & 1) != ((x >> j) & 1))
			x ^= (1 << i) | (1 << j);
		i++;
		j--;
	}
	printf("Value of Reversed Bit is : %d\n", x);
}
main() {
	unsigned int x = 92;
	unsigned int y = x;
	char* str = malloc(32*sizeof(char));
	int count = 0;
	int i = 0;
	while(i < 32) {
		if(x & 1) {
			str[count++] = '1';
		}
		else
			str[count++] = '0';
		
		x >>= 1;
		i++;
	}
	printf("Swapped bits          : %s\n", str);
	count--;
	i = 0;
	while(i < count) {
		if(str[i] != str[count]) {
			char temp = str[i];
			str[i++] = str[count];
			str[count--] = temp;
		}
		else {
			i++;
			count--;
		}
	}
	printf("Original Bit Poistion : %s\n", str);
	ShortMethod(y);
}
