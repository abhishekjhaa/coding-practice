#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

List* RecursiveMerge(List* list1, List* list2) {
 	if(list1 == NULL) {
 		return list2;
	}
 	else if(list2 == NULL)
                return list1;
	else if(list1 == NULL && list2 == NULL)
		return NULL;

	List* mergedHead;
 	if(list1->data < list2->data) {
		mergedHead = list1;
		mergedHead->next = RecursiveMerge(list1->next, list2);
 	}
 	else {
 		mergedHead = list2;
 		mergedHead->next = RecursiveMerge(list1, list2->next);
 	}

	return mergedHead;
}

void SortLists(List* list1, List* list2) {
	List* head;

	if(list1->data <= list2->data)
		head = list1;
	else
		head = list2;

	while(list1 && list2) {
		if(list1->data <= list2->data) {
			while(list1->next && list1->next->data <= list2->data) {
				list1 = list1->next;
			}
			if(list1->next && list2->next) {
				List* node = list2->next;
				list2->next = list1->next;
				list1->next = list2;
				list1 = list2->next;
				list2 = node;
			}
			else if(!list1->next && list1->data <= list2->data) {
				list1->next = list2;
				while(list1)
					list1 = list1->next;	
			}
		}
		else {
                        List* node1 = list1;
			list1 = list2;
			list2 = node1;
		}
	}

	while(head) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("\n");
}

void main() {
	List* list1 = malloc(sizeof(List));
	List* list2 = malloc(sizeof(List));
	int i;
	List* temp1 = list1;
	List* temp2 = list2;
	
	/*list1->data = 2;
	list1->next = malloc(sizeof(List));
	list1 = list1->next;
	list1->data = 5;
	list1->next = malloc(sizeof(List));
        list1 = list1->next;
	list1->data = 7;
	list1->next = NULL;

	list2->data = 3;
        list2->next = malloc(sizeof(List));
        list2 = list2->next;
        list2->data = 11;
	list2->next = NULL;*/

	for(i = 1; i < 6; i++) {
		list1->data = 2*i;
		list2->data = 3*i;
		
		if(i < 5) {
			list1->next = malloc(sizeof(List));
			list2->next = malloc(sizeof(List));
		}
		else {
			list1->next = NULL;
			list2->next = NULL;
		}

                list1 = list1->next;
                list2 = list2->next;
	}
	
	List* pMergedHead = RecursiveMerge(temp1, temp2);
	printf("Recursive Solution Below \n");
	while(pMergedHead) {
		printf("%d -> ", pMergedHead->data);
		pMergedHead = pMergedHead->next;
	}
        printf("\n");

//      	printf("Iterative Solution Below \n");
//      	SortLists(temp2, temp1);


}
