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

int IsSymmetrical(Tree* root1, Tree* root2) {
	if(!root1 && !root2)
		return 1;
	if(!root1 || !root2)
                return 0;
	if(root1->data != root2->data)
		return 0;

	return IsSymmetrical(root1->left, root2->right) && IsSymmetrical(root1->right, root2->left);
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data =                    8;
        MakeTree(root,            6,             6);
        MakeTree(root->left, 5,       7);
        MakeTree(root->right,                  7,   5);
        int result = IsSymmetrical(root, root);
	printf("Tree is %s\n", result > 0 ? "Symmentrical" : "Asymmetrical");
}
