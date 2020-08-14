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
	(*root)->left->right->left->data = 5;
}

int FindDepth(Tree* root) {
	if(!root)
		return 0;
	int left = FindDepth(root->left);
	int right = FindDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data = 1;
        MakeTree(&root);
	int depth = FindDepth(root);
	printf("Depth Of tree is : %d\n", depth);
}

