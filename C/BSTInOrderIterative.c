#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

typedef struct List {
        struct Tree* node;
        struct List* next;
} List;

static int count = 0;

void MakeTree(Tree* root, int leftData, int rightData) {
        if(leftData != 0) {
		root->left = malloc(sizeof(Tree));
        	root->left->data = leftData;
	}
	if(rightData != 0) {
		root->right = malloc(sizeof(Tree));
        	root->right->data = rightData;
	}
}

void Push(Tree* root, List** stack) {
	List* temp = malloc(sizeof(List));
	temp->node = root;
	temp->next = (*stack);
	(*stack) = temp;
}

void Pop(List** stack) {
	printf("%d| ", (*stack)->node->data);
	List* node = (*stack)->next;
	(*stack)->node = NULL;
	*stack = NULL;
	free(*stack);
	*stack = node;
}

void InOrderIterative(Tree* root) {
	List* stack = NULL;
	//Push(root, &stack);

	while(stack || root) {
		if(root) {
			Push(root, &stack);
			root = root->left;
		}
		else {
			root = stack->node;
			Pop(&stack);
			root = root->right;
		}
	}
	
	printf("\n");
}

void main() {
	Tree* root = malloc(sizeof(Tree));
        root->data =                    	43;
        MakeTree(root,               23,             	  47);
        MakeTree(root->left, 0,      	       37);
        MakeTree(root->left->right, 	    29,   41);
	MakeTree(root->left->right->left, 0,   31);
	MakeTree(root->right, 				0,  53);
	InOrderIterative(root);

}
