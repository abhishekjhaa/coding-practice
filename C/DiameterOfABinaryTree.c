#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

void InsertLeftRight(Tree* node, bool insertLeft, bool insertRight) {
	if(insertLeft) {
		Tree* left = malloc(sizeof(Tree));
		left->data = rand() % 100;
		node->left = left;
	}

	if(insertRight) {
		Tree* right = malloc(sizeof(Tree));
		right->data = rand() % 100;
		node->right = right;
	}
}

void MakeTree(Tree* root) {
	// diameter 9 nodes through Root.
	InsertLeftRight(root, true, true);
	InsertLeftRight(root->left, true, true);
        InsertLeftRight(root->right, false, true);
        InsertLeftRight(root->left->right, true, true);
        InsertLeftRight(root->right->right, false, true);
        InsertLeftRight(root->right->right->right, true, true);
        InsertLeftRight(root->right->right->right->left, true, true);
}

void InOrderTraverse(Tree* root) {
	if(!root)
		return;
	InOrderTraverse(root->left);
	printf("%d, ", root->data);
	InOrderTraverse(root->right);
}

int Max(int a, int b) {
	return a > b ? a : b;
}

int Height(Tree* root) {
	if(!root)
		return 0;
	return (1 + Max(Height(root->left), Height(root->right)));
}

int Diameter(Tree* root) {
	// n^2 time complexity.

	if(!root)
		return 0;
	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);
	
	int leftDiameter = Diameter(root->left);
        int rightDiameter = Diameter(root->right);

	return Max((leftHeight + rightHeight + 1), Max(leftDiameter, rightDiameter));
}

int OptimizedDiameter(Tree* root, int* height) {
	// Optimized time complexity n
	if(!root) {
		*height = 0;
		return 0;
	}

	int leftHeight = 0, rightHeight = 0;
	int leftDiameter = OptimizedDiameter(root->left, &leftHeight);
	int rightDiameter = OptimizedDiameter(root->right, &rightHeight);
	
	*height = Max(leftHeight, rightHeight) + 1;
	return Max((leftHeight + rightHeight + 1), Max(leftDiameter, rightDiameter));
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = rand() % 100;
	MakeTree(root);
	InOrderTraverse(root);
	printf("\n");
	
	int diameter = Diameter(root);
	printf("Diameter Of Tree : %d\n", diameter);

	int height = 0;
	diameter = OptimizedDiameter(root, &height);
	printf("Diameter Of Tree : %d\n", diameter);
}
