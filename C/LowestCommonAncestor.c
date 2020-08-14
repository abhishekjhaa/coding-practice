#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

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

Tree* FindLCA(Tree* root, int data1, int data2) {
	if(!root)
		return NULL;
	else if(root->data == data1 || root->data == data2)
		return root;

	Tree* leftSubTree = FindLCA(root->left, data1, data2);
	Tree* rightSubTree = FindLCA(root->right, data1, data2);

	if(leftSubTree && rightSubTree)
		return root;
	else
		return leftSubTree ? leftSubTree : rightSubTree;
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 					81;
	MakeTree(root, 			70, 				90);
	MakeTree(root->left, 	50, 		75);
        MakeTree(root->right, 					85, 		110);
        MakeTree(root->left->right, 	72, 		78);

	Tree* result = FindLCA(root, 78, 72);
	printf("LCA is : %d\n", result->data);
}


