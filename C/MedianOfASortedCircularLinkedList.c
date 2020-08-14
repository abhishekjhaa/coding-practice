#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>

typedef struct List
{
        int data;
        struct List* next;
} List;

void FindMedian(List* start) {
	while(start->data <= start->next->data)
		start = start->next;
	List* begin = start->next;
	List* end = start;

	int numOfElements = 1;
	while(begin != end) {
		printf("%d-> ", begin->data);
		begin = begin->next;
		numOfElements++;
	}

	printf("%d \n", begin->data);
	begin = begin->next;
	printf("No of Elements in Cyclic Sorted Link List is : %d \n", numOfElements);

	if(numOfElements % 2) {
		numOfElements /= 2;
        	while(numOfElements > 0) {
                	begin = begin->next;
        		numOfElements--;
	        }

		printf("Median of the List is %d\n", begin->data);
	}
	else {
		numOfElements /= 2;
		numOfElements--;
                while(numOfElements > 0) {
                	begin = begin->next;
                	numOfElements--;
                }
		
		int median =  (begin->data + begin->next->data) / 2;
		printf("Median of the List is %d\n", median);
	}
}

void main() {
	
	List* list = malloc(sizeof(List));
        List* listHead = list;
        List* start;

        list->data = 6;
        list->next = malloc(sizeof(List));
        list = list->next;

	list->data = 17;
        list->next = malloc(sizeof(List));
        list = list->next;

	list->data = 2;
        list->next = malloc(sizeof(List));
        list = list->next;

	list->data = 2;
        list->next = malloc(sizeof(List));
        list = list->next;

	list->data = 3;
        list->next = listHead;

	start = listHead->next;

	FindMedian(start);
}
