#include<stdio.h>
#include<malloc.h>

typedef struct List {
	int data;
	struct List* next;
} List;

void Push(List** stack, int data, List** maxStack) {
	List* node = malloc(sizeof(List));
	node->data = data;
	node->next = (*stack);
	(*stack) = node;
	printf("Pushed %d into Stack\n", data);

	List* temp = malloc(sizeof(List));
	if(!(*maxStack) || data > (*maxStack)->data)
		temp->data = data;
	else
		temp->data = (*maxStack)->data;     	
	temp->next = (*maxStack);
        (*maxStack) = temp;
}

void Pop(List** stack, List** maxStack) {
	printf("Popped %d\n", (*stack)->data);
	*stack = (*stack)->next;
	*maxStack = (*maxStack)->next;
}

int Max(List** stack, List** maxStack) {
	if(!(*stack))
		return 0;
	return (*maxStack)->data;
}

void main() {
	List* stack = NULL;
	List* maxStack = NULL;
	Push(&stack, 2, &maxStack);
	Push(&stack, 1, &maxStack);
	Push(&stack, 3, &maxStack);
	Push(&stack, 4, &maxStack);
	Push(&stack, 1, &maxStack);
	Push(&stack, 5, &maxStack);
	Push(&stack, 3, &maxStack);

	Pop(&stack, &maxStack);
	int result = Max(&stack, &maxStack);
	printf("Max of the Stack is : %d\n", result);

        Pop(&stack, &maxStack);
        result = Max(&stack, &maxStack);
        printf("Max of the Stack is : %d\n", result);

        Pop(&stack, &maxStack);
        result = Max(&stack, &maxStack);
        printf("Max of the Stack is : %d\n", result);

        Pop(&stack, &maxStack);
        result = Max(&stack, &maxStack);
        printf("Max of the Stack is : %d\n", result);
}
