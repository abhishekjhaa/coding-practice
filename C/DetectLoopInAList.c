#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>

typedef struct List
{
        int data;
        struct List* next;
} List; 

bool DetectLoop(List* list) {
	if(!list || !list->next)
		return false;
	List* slowNode = list;
	List* fastNode = list->next;
	int loopLen = 0;
	while(fastNode && slowNode && slowNode->next && fastNode->next && fastNode->next->next) {
		if(fastNode == slowNode) {
			do {
				fastNode = fastNode->next;
				loopLen++;
			} while(fastNode != slowNode);
			
			printf("Length of the Loop is : %d \n", loopLen);
			fastNode = list;
			while(loopLen > 0) {
				fastNode = fastNode->next;
				--loopLen;
			}

			slowNode = list;
			while(fastNode != slowNode) {
				fastNode = fastNode->next;
				slowNode = slowNode->next;
			}
			
			printf("Loop Starts at Node %d\n", slowNode->data);
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
	List* temp = list;
	List* node;
	int i;
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
	
	for(i = 1; i < 8; i++) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	printf("Loop detected : %s \n", DetectLoop(listHead) ? "true" : "false");
}
