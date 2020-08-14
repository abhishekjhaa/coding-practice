#include<stdio.h>
#include<malloc.h>

typedef struct List {
	char data;
	struct List* next;
	struct List* sibling;
} List;

List* CloneList(List* list) {
	List* head = list;
	while(list) {
		List* temp = malloc(sizeof(List));
		temp->data = list->data;
		List* holdNext = list->next;
		list->next = temp;
		temp->next = holdNext;
		list = holdNext;
	}
	List* start = head;
	while(start) {
		if(start->sibling)
			start->next->sibling = start->sibling->next;
		start = start->next->next;
	}
	List* head2 = head->next;
	List* head3 = head2;
	while(head->next && head2->next) {
		head->next = head->next->next;
		head = head->next;
		head2->next = head2->next->next;
		head2 = head2->next;
	}
	
	return head3;
}

void main() {
	List* list = malloc(sizeof(List));
	list->data = 'A';
	List* head = list;
	int i;
	for(i = 1 ; i < 5; i++) {
		list->next = malloc(sizeof(List));
		list = list->next;
		list->data = 'A' + i;
		list->next = NULL;;
	}
	
	List* start = head;
	start->sibling = head->next->next;
	start = start->next;
	start->sibling = head->next->next->next->next;
	start = start->next->next;
	start->sibling = head->next;

	List* clone = CloneList(head);
	while(clone) {
		if(clone->sibling)
			printf("Sibling of %c is %c\n", clone->data, clone->sibling->data);
		else
			printf("No Sibling for %c\n", clone->data);

		clone = clone->next;
	}
}
