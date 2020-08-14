#include<stdio.h>

int GetHashCode(char* str, int modulo) {
	int value = 0;
	int num = 997; // Any prime will do.
	while(*str) {
		value = (value*num + (*str)) % modulo;
		str++;
	}

	return value;
}

void main() {
	char* str = "Dictionary";
	int modulo = 10; // Size of the Array/Hashmap
	int hashCode = GetHashCode(str, modulo);
	printf("HashCode of %s is %d for a array/hashmap of size %d\n", str, hashCode, modulo);
}
