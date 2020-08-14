#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void MakeList(List* list1, List* list2) {
        List* head1 = list1;
        list1->data = 1;
        list1->next = NULL;
        int i = 2;
        while(i < 8) {
                list1->next = malloc(sizeof(List));
                list1->next->data = i++;
                list1->next->next = NULL;
                list1 = list1->next;
        }

	list1 = head1;

        List* head2 = list2;
        list2->data = 10;
        list2->next = malloc(sizeof(List));
        list2 = list2->next;
        list2->data = 9;
        list2->next =  head1->next->next->next->next;
	
	list2 = head2;

}

void main() {
	List* list1 = malloc(sizeof(List));
	List* list2 = malloc(sizeof(List));
	MakeList(list1, list2);

	List* head1 = list1;
	List* head2 = list2;

	int count = 0;

	printf("List1 : ");
	while(list1) {
		count++;
		printf("%d->",list1->data );
		list1 = list1->next;
	}
	printf("\nList2 : ");
	while(list2) {
		count--;
                printf("%d->",list2->data );
		list2 = list2->next;
	}
	
	if(count > 0) {
		while(count > 0) {
			head1 = head1->next;
			count--; 
		}
	}
	else {
		while(count < 0) {
			head2 = head2->next;
			count++;
		}
	}

	while(head1 && head2) {
		if(head1 == head2) {
			printf("\nTwo lists intersect at %d\n", head1->data);
			return;
		}

		head1 = head1->next;
		head2 = head2->next;
	}
	printf("\nNo intersection of Lists\n");
}
