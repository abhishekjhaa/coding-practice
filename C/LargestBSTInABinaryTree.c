#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<limits.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

void MakeTree(Tree** root) {
	(*root)->left = malloc(sizeof(Tree));
        (*root)->right = malloc(sizeof(Tree));

        (*root)->left->data = 6;
        (*root)->right->data = 9;

        (*root)->left->left = malloc(sizeof(Tree));
        (*root)->right->left = malloc(sizeof(Tree));
        (*root)->right->right = malloc(sizeof(Tree));

        (*root)->left->left->data = 5;
        (*root)->right->left->data = 8;
        (*root)->right->right->data = 10; 
}

bool FindLargestBST(Tree* root, int* min, int* max, int* largestSize) {

	if(!root) {
		(*min) = INT_MAX;
		(*max) = INT_MIN;
		(*largestSize) = 0;
		return true;
	}

	int minLeft, maxLeft, leftSize;
	bool left = FindLargestBST(root->left, &minLeft, &maxLeft, &leftSize);

        int minRight, maxRight, rightSize;
        bool right = FindLargestBST(root->right, &minRight, &maxRight, &rightSize);

	bool overAll = false;
	if(left && right && root->data >= maxLeft && root->data <= minRight) {
		(*largestSize) = leftSize + rightSize + 1;
		overAll = true;
		printf("Largest size under node %d -> is : %d \n", root->data, *largestSize);
		(*min) = root->data < minLeft ? root->data : minLeft;
                (*max) = root->data > maxRight ? root->data : maxRight;
	}
	else 
		(*largestSize) = leftSize > rightSize ? leftSize : rightSize;

	return overAll;		
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 12;
	MakeTree(&root);
	int min, max, largestSize;
	FindLargestBST(root, &min, &max, &largestSize);
	printf("Size Of Largest Binary Search Tree is : %d \n", largestSize);
}
