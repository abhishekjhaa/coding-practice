/*
Implement a function to check if a binary tree is balanced. For the purposes of 
this question, a balanced tree is defined to be a tree such that the heights of the 
two subtrees of any node never differ by more than one. 
*/

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

        (*root)->left->data = 2;
        (*root)->right->data = 3;

        (*root)->left->left = malloc(sizeof(Tree));
        (*root)->left->right = malloc(sizeof(Tree));
        (*root)->right->right = malloc(sizeof(Tree));

        (*root)->left->left->data = 4;
        (*root)->left->right->data = 5;
        (*root)->right->right->data = 6;

	(*root)->left->right->left = malloc(sizeof(Tree));
	(*root)->left->right->left->data = 7;

//	(*root)->left->right->left->right = malloc(sizeof(Tree)); // To make imbalanced tree
//	(*root)->left->right->left->right->data = 9;

}

int FindDepth(Tree* root, bool* isBalanced) {
	if(!root)
		return 0;
	if(*isBalanced) {
		int left = FindDepth(root->left, isBalanced);
		int right = FindDepth(root->right, isBalanced);
		if(left - right > 1 || left - right < -1)
			*isBalanced = false;
		return left > right ? left + 1 : right + 1;
	}

	return 0;
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data = 1;
        MakeTree(&root);
	bool isBalanced = true;
	int depth = FindDepth(root, &isBalanced);
	printf("Tree is : %s\n", isBalanced ? "Balanced" : "Not Balanced");
}

