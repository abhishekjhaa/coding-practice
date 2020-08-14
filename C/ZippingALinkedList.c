#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct List {
        int data;
        struct List* next;
} List;

void MakeList(List** list, int data) {
        (*list)->next = malloc(sizeof(List));
        *list = (*list)->next;
        (*list)->data = data;
}

List* Reverse(List* list) {
        List* prev = NULL;
        List* curr = list;

        while(curr) {
                List* temp = curr->next;
		curr->next = prev;
                prev = curr;
                curr = temp;
        }

        return prev;
}

void ZipList(List* list) {
        List* fast = list;
        List* slow = list;
        // slow is the middle of the list.
        while(fast) {
                fast = fast->next;
                if(fast) {
                        slow = slow->next;
                        fast = fast->next;
                }
        }

        // Reversing from the middle to the last of the list.
        List* reverse = Reverse(slow);
	
	//Interleavinf 1st and 2nd half
        while(list && reverse) {
		List* temp = list->next;
		List* temp1 = reverse->next;
		list->next = reverse;
		list = temp;
		reverse->next = temp;
		reverse = temp1;	
        }
}

void main() {
        List* list = malloc(sizeof(List));
        list->data = 2;
        List* head = list;
        MakeList(&list, 3);
        MakeList(&list, 4);
        MakeList(&list, 5);
        MakeList(&list, 6);
        list = head;
	while(list) {
                printf("%d-> ", list->data);
                list = list->next;
        }
	printf("\n");
	list = head;
        ZipList(list);
	while(list) {
		printf("%d-> ", list->data);
		list = list->next;
	}
	printf("\n");
}
