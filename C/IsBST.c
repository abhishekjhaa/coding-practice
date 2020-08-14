/*Implement a function to check if a binary tree is a binary search tree.*/

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<limits.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

typedef struct Queue {
        int lowerBound;
        int upperBound;
	Tree* node;
        struct Queue* next;
} Queue;

void MakeTree(Tree** root) {
	(*root)->left = malloc(sizeof(Tree));
        (*root)->right = malloc(sizeof(Tree));

        (*root)->left->data = 6;
        (*root)->right->data = 14;

        (*root)->left->left = malloc(sizeof(Tree));
        (*root)->left->right = malloc(sizeof(Tree));

        (*root)->left->left->data = 4;
        (*root)->left->right->data = 8;

        (*root)->right->left = malloc(sizeof(Tree));
        (*root)->right->right = malloc(sizeof(Tree));

        (*root)->right->left->data = 12;
        (*root)->right->right->data = 16;
}

bool IsBSTUsingPreOrder(Tree* root, int min, int max) {
	if(!root)
		return true;	
	
	if(root->data < min || root->data > max)
		return false;

	return IsBSTUsingPreOrder(root->left, min, root->data) && IsBSTUsingPreOrder(root->right, root->data, max);
}

bool IsBSTUsingInOrder(Tree* root, int* prev) {
	if(!root)
		return true;

	bool result =  IsBSTUsingInOrder(root->left, prev) && (root->data >= *prev); 
	*prev = root->data; 
	return result && IsBSTUsingInOrder(root->right, prev);
}

void Enqueue(Queue* queue, Tree* node, int lowerBound, int upperBound) {
	Queue* temp = malloc(sizeof(Queue));
        temp->lowerBound = lowerBound;
        temp->upperBound = upperBound;
        temp->node = node;
	temp->next = NULL;
	
	while(queue->next)
		queue = queue->next;
	queue->next = temp;
}

void Dequeue(Queue** queue) {
	*queue = (*queue)->next;
}

bool UsingBFS(Tree* root) {
	Queue* queue = malloc(sizeof(Queue));
	queue->lowerBound = INT_MIN;
	queue->upperBound = INT_MAX;
	queue->node = root;
	queue->next = NULL;
	
	bool isBST = true;
	
	while(queue) {
		if(queue->node->left) {
			if(queue->node->left->data < queue->lowerBound || queue->node->left->data > queue->upperBound)
				return false;
			Enqueue(queue, queue->node->left, queue->lowerBound, queue->node->data);
		}
		if(queue->node->right) {
			if(queue->node->right->data < queue->lowerBound || queue->node->right->data > queue->upperBound)
                                return false;
                        Enqueue(queue, queue->node->right, queue->node->data, queue->upperBound);
		}

		Dequeue(&queue);
	}

	return true;
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 10;
	MakeTree(&root);
	int min = INT_MIN;
	int max = INT_MAX;
	printf("Tree is BST Using PreOrder : %s \n",IsBSTUsingPreOrder(root, min, max) ? "true" : "false");
        printf("Tree is BST Using InOrder  : %s \n",IsBSTUsingInOrder(root, &min) ? "true" : "false");
	printf("Tree is BST Using BFS  : %s \n",UsingBFS(root) ? "true" : "false");

}
