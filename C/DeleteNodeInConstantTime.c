#include<stdio.h>
#include<malloc.h>

typedef struct List {
	char data;
	struct List* next;
} List;

void DeleteNode(List* deleteNode) {
	if(deleteNode->next) {
		deleteNode->data = deleteNode->next->data;
		deleteNode->next = deleteNode->next->next;
	}
	else {
		free(deleteNode);
	}
}

void main() {
	List* list = malloc(sizeof(List));
	list->data = 'a';
	List* head = list;
	List* head2 = list;
	List* head3 = list;
	List* deleteNode;
	List* deleteNodeLast;
	int i;
	for(i = 1; i < 26; i++) {
		list->next = malloc(sizeof(List));
		if(list->data == 'i')
			deleteNode = list;
		if(i == 25)
			deleteNodeLast = list->next;
		list = list->next;
		list->data = 'a' + i;
		list->next = NULL;
	}

	printf("Original List \n");
	while(head) {
		printf("%c -> ", head->data);
		head = head->next;
	}
	printf("\n");

	DeleteNode(deleteNode);
	while(head2) {
                printf("%c -> ", head2->data);
                head2 = head2->next;
        }
	printf("\n");

	DeleteNode(deleteNodeLast);
	while(head3) {
                printf("%c -> ", head3->data);
                head3 = head3->next;
        }
        printf("\n");
}
