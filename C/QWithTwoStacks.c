#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void Push(List** stack, int data) {
	List* node = malloc(sizeof(List));
	node->data = data;
	node->next = (*stack);
	(*stack) = node;
}

void Queue(List** stack,  int data) {
		printf("Number queued is %d \n", data);
		Push(stack, data);
}

void Pop(List** stack) {
	if(!(*stack)) {
		printf("No items to Dequeue\n");
		return;
	}
	printf("Number dequeued is : %d \n", (*stack)->data);
	List* node = (*stack);
	(*stack) = (*stack)->next;
	free(node); 
}

void DeQueue(List** stack1, List** stack2) {
	if(!(*stack2) && (*stack1)) {
		while((*stack1)) {
			Push(stack2, (*stack1)->data);
			(*stack1) = (*stack1)->next;
		}
	}

	if(!(*stack1) && !(*stack2)) {
		printf("No items to Dequeue\n");
		return;
	}
	
	Pop(stack2);
}

void main() {
	int i;
	List* stack1 = NULL; 
	List* stack2 = NULL;
	for(i = 0; i < 3; i++)
		Queue(&stack1, rand() % 20);
	
	DeQueue(&stack1, &stack2);
        DeQueue(&stack1, &stack2);
	for(i = 0; i < 3; i++)
                Queue(&stack1, rand() % 20);
        DeQueue(&stack1, &stack2);
        DeQueue(&stack1, &stack2);
	DeQueue(&stack1, &stack2);
}
