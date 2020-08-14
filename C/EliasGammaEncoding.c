#include<stdio.h>
#include<malloc.h>

void Reverse(char* number, int count) {
	int i = 0;
	while(i < count) {
		char temp = number[i];
		number[i++] = number[count];
		number[count--] =  temp;
	}
}

char* ConvertToBinary(int x) {
	char* number = malloc(31*sizeof(char));
	int r;
	int count = 0;

	while(x > 0) {
		r = x % 2;
		number[count++] = r + '0';
		x /= 2;	
	}

	Reverse(number, count - 1);

	int i, j;
	int size = 2*count - 1;
	count--;
	char* finalNum = malloc(size*sizeof(char));
	j = 0;

	for(i = 0; i < size; i++) {
		if(count > 0) {
			finalNum[i] = '0';
			count--;
		}
		else
			finalNum[i] = number[j++];
	}

	return finalNum;
}

char* Encode(int array[], int size) {
	int i;
	int count = 0;
	int j = 0;
	char* prevNum = malloc(sizeof(char));
	
	for(i = 0; i < size; i++) {
		char* num = ConvertToBinary(array[i]);
		int k = 0;
		count += sizeof(num);
		prevNum = realloc(prevNum, count);
		while(num[k] != '\0')
			prevNum[j++] = num[k++];	
	}

	return prevNum;
}

int GetInt(char* str, int start, int end) {
	int x = 0;
	
	while(end >= start) {
		x = (x << 1) + (str[start++] - '0');
	}

	return x;
}

int* Decode(char* str) {
	int j = 0;
	int count = 0;
	int* array;
	int k = 0;
	
	while(str[j] != '\0') {
		while(str[j++] != '1')
			count++;
		array[k++] = GetInt(str, j - 1, j + count - 1);
                j += count;
		count = 0;
	}
	
	return array;
}

void main() {
	int array[] = {10,12,5,8};
	int size = 4;
	
	char* encodedString = Encode(array, size);
	printf("Encoded String is : %s\n", encodedString);
	
	int* decodeArray = Decode(encodedString);
	printf("Decoded Integers are : ");
	
	int i = 0;
	while(size > i)
		printf("%d\t", decodeArray[i++]);
	printf("\n");
}
