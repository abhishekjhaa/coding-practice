#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

List* ReverseList(List* list) {
	List* ahead = list->next;
	List* curr = list;
	List* prev = NULL;
	while(ahead) {
		curr->next = prev;
		prev = curr;
		curr = ahead;
		if(ahead->next)
			ahead = ahead->next;
		else {
			curr->next = prev;
			break;
		}
	}
	
	return curr;
}

List* RecursiveReverse(List* list, List** head) {
	if(!list->next) {
		(*head) = list;
		return list;
	}
	List* temp = RecursiveReverse(list->next, head);
	temp->next = list;
	list->next = NULL;
	return list;
}

void main() {
	List* list = malloc(sizeof(List));
	list->data = 1;
	List* head = list;
	int i;
	for(i = 2; i < 10; i++) {
		list->next = malloc(sizeof(List));
		list = list->next;
		list->data = i;
		list->next = NULL;
	}
	
	List* reverseHead = ReverseList(head);
	head = reverseHead;
	while(reverseHead) {
		printf("%d <- ", reverseHead->data);
		reverseHead = reverseHead->next;
	}
	printf("\n");
	List* start = head;
	List* result = RecursiveReverse(head, &start);
	while(start) {
                printf("%d -> ", start->data);
                start = start->next;
        }

	printf("\n");
}
