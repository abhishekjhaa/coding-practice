#include<stdio.h>
#include<malloc.h>

typedef struct Q {
	int data;
	struct Q* next;
} Q;

void RemoveTail(Q** max, Q** maxHead) {
	Q* temp = *maxHead;
	if(*maxHead == *max) {
		*max = NULL;
		*maxHead = NULL;
		return;
	}
	while(temp && temp->next != *max) {
		temp = temp->next;
	}
	temp->next = NULL;
	*max = temp;
}

void AddNode(Q** q, int data) {
	Q* node = malloc(sizeof(Q));
        node->data = data;
        node->next = NULL;
        if(*q)          
                (*q)->next = node;
        *q = node;
}

void Enqueue(Q** q, Q** max, Q** maxHead, int data) {
	AddNode(q, data);
	printf("Enqueued %d\n", data);
	while(*max && (*max)->data < data) {
		RemoveTail(max, maxHead);
	}

	AddNode(max, data);
	if(!(*maxHead))
		*maxHead = *max;
}

void Dequeue(Q** head, Q** maxHead) {
	if(*head) {
		printf("Dequeued %d\n", (*head)->data);
		if(*maxHead && ((*head)->data == (*maxHead)->data)) {
			printf("Dequeued Max %d\n", (*maxHead)->data);
			*maxHead = (*maxHead)->next;
		}
		*head = (*head)->next;
	}
	else
		printf("Empty Queue\n");
	
}

void Max(Q* maxHead) {
	printf("Max in the Q is %d\n", maxHead->data);
}

void main() {
	Q* q = NULL;
	Q* max = NULL;
	Enqueue(&q, &max, &max, 3);
	Q* head = q;
	Q* maxHead = max;

        Enqueue(&q, &max, &maxHead, 1);
        Enqueue(&q, &max, &maxHead, 3);
        Enqueue(&q, &max, &maxHead, 2);
        Enqueue(&q, &max, &maxHead, 0);
        Enqueue(&q, &max, &maxHead, 1);
	
	Max(maxHead);

	Dequeue(&head, &maxHead);
        Dequeue(&head, &maxHead);

        Max(maxHead);

        Enqueue(&q, &max, &maxHead, 2);
        Enqueue(&q, &max, &maxHead, 4);

        Max(maxHead);

        Dequeue(&head, &maxHead);

        Max(maxHead);

        Enqueue(&q, &max, &maxHead, 4);
}
