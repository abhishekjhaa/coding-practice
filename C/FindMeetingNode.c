#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>

typedef struct List
{
        int data;
        struct List* next;
} List; 

void FindMeetingNode(List* list, int* count) {
	List* p1 = list;
	List* p2 = list;
	while(*count > 0) {
		p1 = p1->next;
		(*count)--;
	}
	while(p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	
	printf("Meeting Node found : %d \n", p1->data);
}

bool DetectLoop(List* list, int* count) {
	if(!list || !list->next)
		return false;
	List* slowNode = list;
	List* fastNode = list->next;
	while(fastNode && slowNode) {
		if(fastNode == slowNode) {
			fastNode = fastNode->next;
			(*count)++;
			while(fastNode != slowNode) {
				(*count)++;
				fastNode = fastNode->next;
			}
			return true;
		}
		slowNode = slowNode->next;
		fastNode = fastNode->next;
		
		if(fastNode)
			fastNode = fastNode->next;
	}
	
	return false;
}

void main() {
	List* list = malloc(sizeof(List));
        List* listHead = list;
	List* node;
	int i; 
	int count = 0;
        for(i = 1; i < 7; i++)
        {
		if(i < 6) {
               		list->data = i;
               		list->next = malloc(sizeof(List));
               		list = list->next;
		}
		if(i == 2) {
			node = list;
		}
		if(i == 6) {
                        list->data = i;
			list->next = node;			
		}
			
        }
	
	if(DetectLoop(listHead, &count)) {	

		printf("Loop detected : %s and  No of nodes in loop is : %d\n", DetectLoop(listHead, &count) ? "true" : "false", count);
		FindMeetingNode(listHead, &count);
	}
}
