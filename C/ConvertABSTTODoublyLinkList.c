#include<stdio.h>
#include<malloc.h>

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

void InOrderTraversal(Tree* root, Tree** node) {
	if(!root)
		return;
	InOrderTraversal(root->left, node);
	root->left = *node; // Imp Step.
	if(*node) {
		(*node)->right = root;
	}
	*node = root;
	InOrderTraversal(root->right, node);
}

void main() {
	Tree* root = malloc(sizeof(Tree));
        root->data =                    8;
        MakeTree(root,            6,             10);
        MakeTree(root->left, 5,       7);
        MakeTree(root->right,                  9,   11);
	Tree* node = NULL;
	InOrderTraversal(root, &node);
	Tree* head;
	while(node) {
		printf("%d ", node->data);
		head = node;
		node = node->left;
	}
	printf("\n");
	while(head) {
                printf("%d ", head->data);
                head = head->right;
        }
	printf("\n");
}
