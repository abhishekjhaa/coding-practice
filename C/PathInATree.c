/*You are given a binary tree in which each node contains a value. Design an algo- 
rithm to print all paths which sum to a given value. The path does not need to start 
or end at the root or a leaf. */

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

typedef struct List {
	int data;
	struct List* next;
} List;

void MakeTree(Tree* root, int leftData, int rightData) {
        root->left = malloc(sizeof(Tree));
        root->right = malloc(sizeof(Tree));
        root->left->data = leftData;
        root->right->data = rightData;
}

void FindSum(Tree* root, int pathSum, int sum, List* stack) {	
	if(!root)
		return;

	List* node = malloc(sizeof(List));
	node->data = root->data;
	node->next = stack;
	stack = node;

	pathSum += root->data;
        List* head = stack;
	
	// We can comment out the 'if' part to shorten the code. else is taking care of all the cases.
	if(pathSum == sum) {	// This is the path originating from the root of the tree.
		while(stack) {
			printf("%d + ",stack->data);
			stack = stack->next;
		}
		printf("0 = %d\n", sum);
	}
	else {	// Check for partial paths
		int tempSum = 0;
		List* tempStack = stack;
		while(tempStack) {
			tempSum += tempStack->data;
			if(tempSum == sum) {
				tempStack = tempStack->next; // Moving it a step ahead so that the below while loop will end where it should.
				while(stack != tempStack) {
					printf("%d + ", stack->data);
					stack = stack->next;
				}
				printf("0 = %d\n", sum);
				break;
			}

			tempStack = tempStack->next;
		}
	}

	stack = head;
	if(root->left)
		FindSum(root->left, pathSum, sum, stack);
        if(root->right)
		FindSum(root->right, pathSum, sum, stack);

	stack = stack->next;
}

void main() {
	Tree* root = malloc(sizeof(Tree));
        root->data =                    10;
        MakeTree(root,            5,             12);
        MakeTree(root->left, 4,       7);
	List* stack = NULL;
	int sum = 22;
	int pathSum = 0;
	FindSum(root, pathSum, sum, stack);
}
