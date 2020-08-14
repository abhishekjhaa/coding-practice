#include<stdio.h>
#include<malloc.h>
#include<limits.h>

#define SIZE 15

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

Tree* ConstructBST(int* preOrder, int start, int end, int min, int max) {
	if(start < end) {
		if(preOrder[start] < min || preOrder[start] > max)
			return NULL;
		Tree* node = malloc(sizeof(Tree));
		node->data = preOrder[start];
		int count = start + 1;
		while(preOrder[count] < preOrder[start] && count < end)
			count++;
		node->left = ConstructBST(preOrder, start + 1, count, min, preOrder[start]);
		node->right = ConstructBST(preOrder, count, end, preOrder[start], max);
		return node;
	}

	return NULL;
}

// This computes faster.
Tree* ConstructBST2(int* preOrder, int* start, int min, int max) {
        if(*start == SIZE)
		return NULL;
	int current = preOrder[*start];
        if(current < min || current > max)
	        return NULL;
        Tree* node = malloc(sizeof(Tree));
        node->data = current;
	(*start)++;
        node->left = ConstructBST2(preOrder, start, min, current);
        node->right = ConstructBST2(preOrder, start, current, max);
        return node;
}


void InOrderTraverse(Tree* root) {
	if(!root)
		return;
	InOrderTraverse(root->left);
	printf("%d-> ", root->data);
	InOrderTraverse(root->right);
}

void main() {
	int preOrder[SIZE] = {19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 29, 41, 31, 47, 53};
	int min = INT_MIN;
	int max = INT_MAX;
	Tree* root = ConstructBST(preOrder, 0, SIZE, min, max);
	InOrderTraverse(root);
	printf("\n");

	int start = 0;
	Tree* root1 = ConstructBST2(preOrder, &start, min, max);
        InOrderTraverse(root1);
        printf("\n");
}
