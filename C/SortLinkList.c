#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void SortList(List* list) {
	List* prev = list;
	List* head = list;
	List* ahead = list->next;

	while(ahead) {
		if(ahead->data < head->data) {
			prev->next = ahead->next;
			ahead->next = head;
			head = ahead;
		}
		else {
			List* node = head;
			while(node != prev && node->next->data < ahead->data) {
				node = node->next;				
			}
			if(node != prev) {
				prev->next = ahead->next;
				ahead->next = node->next;
				node->next = ahead;
			}
			else
				prev = prev->next;
		}
		
		ahead = prev->next;
		
	}
	

	
	while(head) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	
	printf("\n");
}

void main() {
	List* list; 
	list = malloc(sizeof(List));
	List* head = list;
	int i;
	for(i = 4; i > 0; i--) {
		list->data = i;
		list->next = malloc(sizeof(List));
		list = list->next;
	}

	list = head;
	while(head) {
		printf("%d -> ", head->data);
		head = head->next;
	}

	printf("\n");

	SortList(list);
}
