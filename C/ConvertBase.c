#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

// Convert A Decimal Number to Hexadecimal Number.

typedef struct List {
	char data;
	struct List* next;
} List;

bool IsDigit(char c) {
	return ((c - '0') >= 0 && (c - '0') <= 9);
}

List* ConvertDecimalToHexa(int base1, int base2, char* number) {
	char* temp = number;
	int length = 0;
	while(*temp != '\0') {
		length++;
		temp++;
	}
	bool isNegative;
	if(number[0] == '-')
		isNegative = true;
	int x = 0;
	int i;
	for(i = isNegative ? 1 : 0; i < length; i++) {
		x *= base1;
		x += IsDigit(number[i]) ? number[i] - '0' : number[i] - 'A' + 10; 
	}
	
	int r;
	List* list = NULL;
	while(x > 0) {
		r = x % base2;
		List* node = malloc(sizeof(List));
		if(base2 == 16)
			node->data = r < 10 ? r + '0' : r + 'A' - 10;
		node->next = list;
		list = node;
		x /= base2;
	} 

	if(isNegative) {
		List* node = malloc(sizeof(List));
                node->data = '-';
                node->next = list;
                list = node;

	}
	
	return list;
}

void main() {
	int base1 = 10;
	int base2 = 16;
	char* number = "-15";
	List* result = ConvertDecimalToHexa(base1, base2, number);
	printf("Number %s in base %d is being converted to base %d:\n",number, base1, base2);
	while(result) {
		printf("%c", result->data);
		result = result->next;
	}
	printf("\n");
}
