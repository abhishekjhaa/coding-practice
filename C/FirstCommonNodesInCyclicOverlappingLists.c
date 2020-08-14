#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void MakeList(List* list1, List* list2) {
        List* head1 = list1;
        list1->data = 1;
        list1->next = NULL;
	List* temp;
        int i = 2;
        while(i < 8) {
                list1->next = malloc(sizeof(List));
                list1->next->data = i++;
                list1->next->next = NULL;
                list1 = list1->next;
		if(i == 4)
			temp = list1;
        }
	
	list1->next = temp;

	list1 = head1;

        List* head2 = list2;
        list2->data = 10;
        list2->next = malloc(sizeof(List));
        list2 = list2->next;
        list2->data = 9;
        list2->next =  head1->next->next->next->next;
	
	list2 = head2;

}

bool CheckIfListIsCyclic(List* list1) {
	List* fast = list1;
	List* slow = list1;
	while(fast && slow && slow->next && fast->next && fast->next->next) {
		if(fast == slow) {
			return true;
		}
		fast = fast->next->next;
		slow = slow->next;
	}

	return false;
}

void GetTheOverLapNode(List* list1, int count) {
	int tempCount = 0;
	List* tempNode = list1;
	while(tempCount < count) {
        	list1 = list1->next;
        	tempCount++;
        }

        while(tempNode != list1) {
        	list1 = list1->next;
                tempNode = tempNode->next;
        }

        printf("List Entered at %d \n", list1->data);
}

void main() {
	List* list1 = malloc(sizeof(List));
	List* list2 = malloc(sizeof(List));
	MakeList(list1, list2);

	List* head1 = list1;
	List* head2 = list2;

	int count = 0;
	int i;
	for(i = 0; i < 8; i++) {
		printf("%d-> ", list1->data);
		list1 = list1->next;
	}
	printf("\n");
	for(i = 0; i < 8; i++) {
                printf("%d-> ", list2->data);
                list2 = list2->next;
        }
	printf("\n");

	list1 = head1;
	list2 = head2;

	bool list1IsCyclic = CheckIfListIsCyclic(list1);
	bool list2IsCyclic = CheckIfListIsCyclic(list2);

	if(list1IsCyclic || list2IsCyclic) {
		while(list1 != list2) {
			list1 = list1->next;
			list2 = list2->next->next;
		}

		do {
			list1 = list1->next;
			count++;
		} while(list1 != list2);
	
		printf("Cycle Length is : %d \n", count);

		list1 = head1;
		GetTheOverLapNode(list1, count);
		list2 = head2;
                GetTheOverLapNode(list2, count);
		return;
	}	

	printf("\nNo intersection of Lists\n");
}
