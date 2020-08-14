#include<stdio.h>
#include<malloc.h>
typedef struct List {
	int data;
	struct List* next;
} List;

void PrintReverseList(List* list) {
	if(list == NULL) {
		return;
	}

	PrintReverseList(list->next);
	printf("%d <- ", list->data);
}

void main() {
	int i;
	List* list = malloc(sizeof(List));
	List* head = list;
	for(i = 0; i < 20; i++) {
		list->data = i;
		if(i != 19) {
			list->next = malloc(sizeof(List));
			list = list-> next;
		}
		else
			list->next = NULL;
	}

	PrintReverseList(head);	
	printf("\n");
}
