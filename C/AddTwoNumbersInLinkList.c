/*
You have two numbers represented by a linked list, where each node contains a 
single digit. The digits are stored in reverse order, such that the 1's digit is at the 
head of the list. Write a function that adds the two numbers and returns the sum 
as a linked list. 

FollowUp : Suppose the digits are stored in forward order. Repeat the above problem.
My Solution is for FollowUp part.
*/

#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void MakeList(List** list, int data) {
	List* node = malloc(sizeof(List));
	node->data = data;
	node->next = *list;
	*list = node;
}

List* GetNumberInLinkList(int number) {
	List* list = NULL;
	while(number) {
		int remainder = number % 10;
		MakeList(&list, remainder);
		number = number / 10;
	}

	return list;
}

void AddNumbers(List* num1, List* num2, List** sum, int* carry) {
	if(!num1 && !num2)
		return;
	if(num1->next && num2->next)
		AddNumbers(num1->next, num2->next, sum, carry);
	else if(num1->next && !(num2->next))
		AddNumbers(num1->next, num2, sum, carry);
	else if(!(num1->next) && num2->next)
                AddNumbers(num1, num2->next, sum, carry);
	int added =  num1->data + num2->data + *carry;
//	printf("%d %d %d\n", num1->data, num2->data, *carry);
	int remainder = added % 10;
	*carry = added / 10;
	MakeList(sum, remainder);
}

void PadZeros(List** num, int difference) {
	while(difference--)
        	MakeList(num, 0); // padding the shorter digit with 0s
}

int Length(List* num) {
	int count = 0;
	while(num) {
		count++;
		num = num->next;
	}

	return count;
}

void main() {
	List* num1 = GetNumberInLinkList(1817); // num1->8->1->7->null
	List* num2 = GetNumberInLinkList(295); // num2->2->9->5->null
	int carry = 0;
	List* sum = NULL;
	int len1 = Length(num1);
	int len2 = Length(num2);
	int difference =  len1 - len2;
	
	if(difference > 0)
		PadZeros(&num2, difference); //Imp step
	else if(difference < 0)
		PadZeros(&num1, -1*difference);

	AddNumbers(num1, num2, &sum, &carry);

	if(carry)
		MakeList(&sum, carry);
	while(sum) {
		printf("%d-> ", sum->data);
		sum = sum->next;
	}
	printf("\n");
}
