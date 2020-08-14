#include<stdio.h>
#include<malloc.h>
// This Binary Search Tree Example
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

int FindLCA(Tree* root, int data1, int data2) {
	if(!root)
		return 0;
	if(root->data > data1 && root->data > data2)
		return FindLCA(root->left, data1, data2);
	else if(root->data < data1 && root->data < data2)
                return FindLCA(root->right, data1, data2);
	else
		return root->data;
}

void Swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int FindLCAIterative(Tree* root, int data1, int data2) {
	while(1) {
		if(root->data > data1 && root->data > data2)
			root = root->left;
		else if(root->data < data1 && root->data < data2)
			root = root->right;
		else
			return root->data;
	}
}

int FindLCAIterative2(Tree* root, int data1, int data2) {
	if(data1 > data2)
        	Swap(&data1, &data2);
        while(root->data < data1 || root->data > data2) {
                if(root->data < data1)
                        root = root->right;
                else if(root->data > data2)
                        root = root->left;
        }
	
	return root->data;
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 					81;
	MakeTree(root, 			70, 				90);
	MakeTree(root->left, 	50, 		75);
        MakeTree(root->right, 					85, 		110);
        MakeTree(root->left->right, 	72, 		78);
	
	int data1 = 78, data2 = 72;
	int result = FindLCA(root, data1, data2);
	printf("LCA is : %d\n", result);

	result = FindLCAIterative(root, data1, data2);
        printf("LCA is : %d\n", result);

        result = FindLCAIterative2(root, data1, data2);
        printf("LCA is : %d\n", result);
}


