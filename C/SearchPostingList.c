#include<stdio.h>
#include<malloc.h>

static int count = 1;

typedef struct List {
	char data;
	int order;
	struct List* jumpTo;
	struct List* next;
} List;

typedef struct Stack {
	struct List* data;
	struct Stack* next;
} Stack;

void Push(Stack** stack, List* data) {
	Stack* node = malloc(sizeof(Stack));
	node->data = data;
	node->next = *stack;
	*stack = node;
}

List* Pop(Stack** stack) {
	Stack* temp = *stack;
	*stack = (*stack)->next;
	return temp->data;
}

void MakeList(List** list, char data) {
	List* node = malloc(sizeof(List));
	node->data = data;
	node->order = -1;
	node->next = *list;
	*list = node;
	
}

void ComputeJumpFirstOrderRecursive(List* list) {
	if(list && list->order == -1) {
		list->order = count++; 
		ComputeJumpFirstOrderRecursive(list->jumpTo);
		ComputeJumpFirstOrderRecursive(list->next);
	}
}

void ComputeJumpFirstOrderIterative(List* list) {
	int countOrder = 1;
	Stack* stack = NULL;
	Push(&stack, list);

	while(stack && stack->data->order == -1) {
		list = Pop(&stack);
		list->order = countOrder++;
		Push(&stack, list->next);
		Push(&stack, list->jumpTo);
	}
}

void main() {
	List* list = NULL;
	MakeList(&list, 'd');
	MakeList(&list, 'c');
	MakeList(&list, 'b');
	MakeList(&list, 'a');

	List* head = list;

	list->jumpTo = list->next->next;
	list = list->next;
	list->jumpTo = list->next->next;
	list = list->next;
	list->jumpTo = head->next;
	list = list->next;
	list->jumpTo = list;

	list = head;
	ComputeJumpFirstOrderRecursive(list);
	
	while(list) {
               	printf("%d -> ", list->order);
		list->order = -1; // For Iterative Process to be completed
               	list = list->next;
        }
	printf("\n");

	list = head;
	ComputeJumpFirstOrderIterative(list);

	while(list) {
                printf("%d -> ", list->order);
                list = list->next;
        }
        printf("\n");

}
