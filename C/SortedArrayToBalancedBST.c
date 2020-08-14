/*
Given a sorted (increasing order) array with unique integer elements, write an 
algorithm to create a binary search tree with minimal height. 
*/

#include<stdio.h>
#include<malloc.h>

#define LENGTH 15

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

typedef struct Queue {
	Tree* node;
	struct Queue* next;
} Queue;

Tree* MakeBalancedBST(int* array, int start, int end) {
	if(start <= end) {
		int mid =  start + (end - start) / 2;
		Tree* node = malloc(sizeof(Tree));
		node->data = array[mid];
		node->left = MakeBalancedBST(array, start, mid - 1);
		node->right = MakeBalancedBST(array, mid + 1, end);
		return node;
	}

	return NULL;
}

void InOrderTraverse(Tree* root) {
	if(!root)
		return;
	InOrderTraverse(root->left);
	printf("%d-> ", root->data);
	InOrderTraverse(root->right);
}

void Enqueue(Queue* queue, Tree* node) {
	Queue* temp = malloc(sizeof(Queue));
        temp->node = node;
        temp->next = NULL;
	
	while(queue->next)
		queue = queue->next;
	queue->next = temp;
}

void Dequeue(Queue** queue) {
	*queue = (*queue)->next;
}

void PrintNodeLevelWise(Tree* root) {
	Queue* queue = malloc(sizeof(Queue));
	queue->node = root;
	queue->next = NULL;
	int count = 0, levelCount = 1, currentLevelCount = 0;
	while(queue) {
		while(count < levelCount) {
			printf("%d | ", queue->node->data);
			if(queue->node->left) {
				Enqueue(queue, queue->node->left);
				currentLevelCount++;
			}
			if(queue->node->right) {
                                Enqueue(queue, queue->node->right);
                               	currentLevelCount++;
                        }
			
			Dequeue(&queue);
			count++;
		}

		printf("\n");
		levelCount = currentLevelCount;
		count = 0;
		currentLevelCount = 0;
	}

	int l = LENGTH;
	count = 1;
	while(l >>= 1) { //Right Shift the number by 1 till it becomes zero.
		count++;
	}

	printf("Expected Number Of Levels = %d\n", count);
}

void main() {
	int length = LENGTH;
	int sortedArray[LENGTH] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	Tree* result = MakeBalancedBST(sortedArray, 0, length - 1);
	InOrderTraverse(result);
	printf("\n");

	PrintNodeLevelWise(result);
}
