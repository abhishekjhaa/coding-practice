#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void DeleteDuplicate(List* list) {
	while(list->next) {
		while(list->data == list->next->data) {
			if(list->next->next)
				list->next = list->next->next;
			if(!list->next->next) {
				list->next = NULL;
				free(list->next);
				return;
			}
		}
		
		list = list->next;
	}
}

void main() {
	List* list = malloc(sizeof(List));
	list->data = 1;
	List* head = list;
	List* head2 = list;
	int i;
	for(i = 2; i < 12; i++) {
		list->next = malloc(sizeof(List));
		list = list->next;
		list->data = i;
		if(i == 3 || i == 4 || i == 5)
			list->data = 3;
		if(i == 6 || i == 7)
			list->data = 4;
		if(i == 10 || i == 11)
			list->data = 10;
		list->next = NULL;
	}
	
        while(head2) {
                printf("%d -> ", head2->data);
                head2 = head2->next;
        }
	printf("\n");

	DeleteDuplicate(head);
	
	while(head) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("\n");
}
