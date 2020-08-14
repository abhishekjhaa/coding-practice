#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct List {
        int data;
        struct List* next;
} List;

void main() {
	List* list = malloc(sizeof(List));
	List* head = list;
	int i;
	
	for(i = 0; i < 9; i++) {
		list->data = i;
		list->next = malloc(sizeof(List));
		list = list->next;
	}
	list->data = 9;
	
	list = head;
	while(list) {
		printf("%d-> ", list->data);
		list = list->next;
	}
	printf("\n");

	List* evenHead = head;
	List* oddHead = head->next;

	List* tempEven = evenHead;
	List* tempOdd = oddHead;

	while(evenHead && oddHead && evenHead->next && oddHead->next) {
		evenHead->next = evenHead->next->next;
		oddHead->next = oddHead->next->next;
		
		evenHead = evenHead->next;
		oddHead = oddHead->next;
	}
	
	evenHead->next = tempOdd;

	list = head;
        while(list) {
                printf("%d-> ", list->data);
                list = list->next;
        }
        printf("\n");
}
