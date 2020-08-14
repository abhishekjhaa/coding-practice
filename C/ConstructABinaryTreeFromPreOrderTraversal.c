#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

typedef struct Stack {
	Tree* tree;
	struct Stack* next;
} Stack;

Tree* ConstructTreeRecursively(int* preOrder, int* start, int end) {
	if(*start <= end) {
		if(preOrder[*start] == 0)
			return NULL;
		Tree* node = malloc(sizeof(Tree));
		node->data = preOrder[*start];
		if(preOrder[*start + 1] != 0) {
			*start += 1;
			node->left = ConstructTreeRecursively(preOrder, start, end);
		}
		else if(preOrder[*start + 1] == 0 && preOrder[*start + 2] != 0) {
			*start += 1;
			node->right = ConstructTreeRecursively(preOrder, start, end);
		}
		else if(preOrder[*start + 1] == 0 && preOrder[*start + 2] == 0) {
			*start += 2;
			return node;
		}
		
		*start += 1;
		node->right = ConstructTreeRecursively(preOrder, start, end);
	
		return node;
	}

	return NULL;
}

Tree* ConstructTree(int* preOrder, int length) {
	int start = 0;
	int end = length - 1;
	return ConstructTreeRecursively(preOrder, &start, end);
}

void PreOrderTraversal(Tree* root) {
        if(!root)
                return;
        printf("%d| ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
}

void Push(Stack** stack, int data) {
	Stack* node = malloc(sizeof(Stack));
	Tree* tree = malloc(sizeof(Tree));
	node->tree = tree;
	node->tree->data = data;
	node->next = *stack;
	*stack = node;
}

Tree* UsingStack(int* preOrder, int length) {
	int end = length - 1;
	Stack* stack;
	while(end >= 0) {
		if(preOrder[end] == 0)
			Push(&stack, preOrder[end]);
		else {
			Tree* left = stack->tree;
			stack = stack->next;
			Tree* right = stack->tree;
			stack = stack->next;
			Push(&stack, preOrder[end]);
			if(left->data != 0) 
				stack->tree->left = left;
			if(right->data != 0)
				stack->tree->right = right;		
		}

		end--;
	}
	
	return stack->tree;
}

void main() {
	int preOrder[] = {1, 2, 3, 0, 0, 4, 5, 0, 0, 0, 6, 0, 7, 0, 8, 9, 0, 0, 0};
	int length = 19;
	Tree* root = ConstructTree(preOrder, length);
	PreOrderTraversal(root);
	printf("\n");
	root = UsingStack(preOrder, length);
	PreOrderTraversal(root);
        printf("\n");
}
