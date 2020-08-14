#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
} Tree;

void MakeTree(Tree* root, int leftData, int rightData) {
        if(leftData != -1) {
                root->left = malloc(sizeof(Tree));
                root->left->data = leftData;
        }
        if(rightData != -1) {
                root->right = malloc(sizeof(Tree));
                root->right->data = rightData;
        }
}

bool IsSymmetric(Tree* left, Tree* right) {
	if(!left && !right)
		return true;
	else if(left && right && left->data == right->data)
		return (IsSymmetric(left->right, right->left) && IsSymmetric(left->left, right->right));
	else
		return false;
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data =                                    314;
        MakeTree(root,                          6,                                              6);
        MakeTree(root->left,            -1,               2);
        MakeTree(root->left->right,                     -1,    3);
        MakeTree(root->right,                                                   2,                      -1);
        MakeTree(root->right->left,                                        3,       -1);

        bool result = IsSymmetric(root->left, root->right);
	if(result)
		printf("Tree is symmetric around root %d\n", root->data);
	else
		printf("Tree is not symmetric around root %d\n", root->data);
}

