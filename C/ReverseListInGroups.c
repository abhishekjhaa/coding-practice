#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

List* Reverse(List* start, List* end) {
	List* ahead = start->next;
        List* behind = start;
        List* temp = NULL;
        while(ahead && ahead != end->next) {
                behind->next = temp;
                temp = behind;
                behind = ahead;
                if(ahead->next)
                        ahead = ahead->next;
                else {
                        break;
                }
        }

	behind->next = temp;
	return behind;	
}

List* ReverseInGroup(List* list, int limit) {
	List* head = list;
	List* listToNext;
	int count = 0;
	int flag = 0;
	while(list) {
		int i;
		List* tempHead = list;
		for(i = 0; (i < limit - 1) && list->next; i++)
			list = list->next;
		List* listNext = list->next;
		List* start = Reverse(tempHead, list);
		if(flag == 0) {
			head = start;
			flag = 1;
			listToNext = tempHead;
		}
		else {
			listToNext->next = start;
			listToNext = tempHead;
		}

		list = listNext;
	}
	
	return head;
}

void main() {
	List* list = malloc(sizeof(List));
        list->data = 1;
        List* head = list;
        int i;
        for(i = 2; i < 11; i++) {
                list->next = malloc(sizeof(List));
                list = list->next;
                list->data = i;
                list->next = NULL;
        }
	
	List* listNew = ReverseInGroup(head, 3);
	while(listNew) {
		printf("%d -> ", listNew->data);
		listNew = listNew->next;
	}
	
	printf("\n");
}
