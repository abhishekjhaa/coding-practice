/*You have two very large binary trees: T1, with millions of nodes, and T2, with 
hundreds of nodes. Create an algorithm to decide if T2 is a subtree of Tl. 
A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n 
is identical to T2. That is, if you cut off the tree at node n, the two trees would be 
identical. */

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

void MakeTree(Tree* root, int leftData, int rightData) {
	root->left = malloc(sizeof(Tree));
	root->right = malloc(sizeof(Tree));
	root->left->data = leftData;
	root->right->data = rightData;
}

int CheckForSubTree(Tree* root, Tree* subRoot) {
	if(!subRoot)	// Subtree has exausted hence it is in the tree.
		return 1;

	if(!root)
		return 0;

	if(root->data != subRoot->data)
		return 0;
	
	return CheckForSubTree(root->left, subRoot->left) && CheckForSubTree(root->right, subRoot->right);
}

int SearchSubTree(Tree* root, Tree* subRoot) {
	int result = 0;
	if(root && subRoot) {
		if(root->data == subRoot->data)
			result = CheckForSubTree(root, subRoot);
		if(!result)
			result = (SearchSubTree(root->left, subRoot) || SearchSubTree(root->right, subRoot));
	}

	return result;
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 			8;
	MakeTree(root, 	          8, 		7);
	MakeTree(root->left, 9,       2);
	MakeTree(root->left->right, 4,  7);

	Tree* subRoot = malloc(sizeof(Tree));
	subRoot->data =     2;
	MakeTree(subRoot, 4,  7);
	
	int result = SearchSubTree(root, subRoot);
	printf("SubTree Found : %s\n", result ? "true" : "false");
}
