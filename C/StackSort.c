#include<stdio.h>
#include<malloc.h>

typedef struct Stack {
        int data;
        struct Stack* next;
} Stack;

void Push(Stack** stack, int data) {
        Stack* node = malloc(sizeof(Stack));
        node->data = data;
        node->next = *stack;
        *stack = node;
}

void Pop(Stack** stack) {
        *stack = (*stack)->next;
}

void Insert(Stack** stack, int data) {
	if(!(*stack) || (data >= (*stack)->data)) {
		Push(stack, data);
	}
	else {
		int temp = (*stack)->data;
		Pop(stack);
		Insert(stack, data);
		Push(stack, temp);
	}
}

void Sort(Stack** stack) {
	if(*stack) {
		int data = (*stack)->data;
		printf("%d-> ", data);
		Pop(stack);
		Sort(stack);
		Insert(stack, data);
	}
}


void main() {
	int stackSize = 10;
	Stack* stack = NULL;
	while(stackSize > 0) {
		Push(&stack, rand() % 20);
		stackSize--;
	}
	printf("Unsorted Stack : ");
	Sort(&stack);
	printf("\nSorted Stack   : ");
	while(stack) {
		printf("%d-> ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}
