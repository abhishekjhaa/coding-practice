#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct List {
        int data;
        struct List* next;
} List;

bool RecursiveSearch(List* list, List** head) {
        if(!list->next) {
		printf("Haha\n");
                if((*head)->data == list->data) {
			(*head) = (*head)->next;
                	return true;
		}
		else
			return false;
        }

	if(RecursiveSearch(list->next, head))
		if(list->data == (*head)->data) {
			(*head) = (*head)->next;
			return true;
		}

	return false;
		
}

void MakeList(List** list, int data) {
	(*list)->next = malloc(sizeof(List));
	*list = (*list)->next;
        (*list)->data = data;
}

List* Reverse(List* list) {
	List* prev = NULL;
	List* curr = list;
	List* nxt = list->next;

	while(nxt) {
		curr->next = prev;
		prev = curr;
		curr = nxt;
		nxt = nxt->next;
	}

	return curr;
}

bool IsLLAPalindrome(List* list) {
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
	slow = Reverse(slow);
	while(list && slow) {
		if(list->data != slow->data)
			return false;
		list = list->next;
		slow = slow->next;
	}

	return true;
}

void main() {
        List* list = malloc(sizeof(List));
        list->data = 2;
	List* head = list;
	MakeList(&list, 3);
        MakeList(&list, 5);
        MakeList(&list, 3);
        MakeList(&list, 1);
	list = head;
	bool result = RecursiveSearch(list, &head);
        printf("Recursive Way: List is Palindrome : %s\n", result ? "true" : "false");
	result = IsLLAPalindrome(list);
	printf("Iterative Way: List is Palindrome : %s\n", result ? "true" : "false");	 
}
