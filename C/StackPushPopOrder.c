#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void main() {
	List* stack = malloc(sizeof(List));
	int sequenceToBePushed[] = {1,2,3,4,5};
	int sequenceToPop[] = {4,5,3,2,1}; // valid Sequence
	//int sequenceToPop[] = {4,3,5,1,2}; // invalid Sequence
	int i = 0;
	int j = 0;
	stack->data = sequenceToBePushed[i++];
	stack->next = NULL;
	List* head = stack;
	while(j < 5) {
		while(head->data != sequenceToPop[j]) {
			List* node = malloc(sizeof(List));
			node->data = sequenceToBePushed[i++];
			node->next = head;
			head = node;	
		}
		if(head->data == sequenceToPop[j]) {
			if(head->next)
				head = head->next;
			else {
				printf("Pop Sequence is Valid\n");
				return;
			}
			j++;
		}
	}
	printf("Pop Sequence is not Valid\n");
	return;
}
