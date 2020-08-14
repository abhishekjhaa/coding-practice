#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
	struct Tree* parent;
} Tree;

void MakeTree(Tree* root, int leftData, int rightData) {
        if(leftData != -1) {
                root->left = malloc(sizeof(Tree));
                root->left->data = leftData;
		root->left->parent = root;
        }
        if(rightData != -1) {
                root->right = malloc(sizeof(Tree));
                root->right->data = rightData;
		root->right->parent = root;
        }
}

static int count = 0;

void InOrderTraverse(Tree* currentNode) {
	Tree* prevParent = NULL;
	Tree* nextChild;
	while(currentNode) {
		if(!prevParent || prevParent->left == currentNode || prevParent->right == currentNode) {
			if(currentNode->left)
				nextChild = currentNode->left;
			else {
				printf("%d| ", currentNode->data);
				nextChild = (currentNode->right ? currentNode->right : currentNode->parent);
			}
		}
		else if(currentNode->left == prevParent) {
			printf("%d| ", currentNode->data);
			nextChild = (currentNode->right ? currentNode->right : currentNode->parent);
		}
		else
			nextChild = currentNode->parent;

		prevParent = currentNode;
		currentNode = nextChild;
	}
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data =                                    4;
	root->parent = NULL;
        MakeTree(root,                          1,                                              7);
        MakeTree(root->left,            -1,               2);
        MakeTree(root->left->right,                     -1,    3);
        MakeTree(root->right,                                                   6,                      -1);
        MakeTree(root->right->left,                                        5,       -1);

	InOrderTraverse(root);
	printf("\n");
}
