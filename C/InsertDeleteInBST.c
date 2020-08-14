#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

void Insert(Tree** root, int key) {
	Tree* node = malloc(sizeof(Tree));
	node->data = key;
	node->left = NULL;
	node->right = NULL;

	if(!(*root))
		*root = node;
	else {
		Tree* current = *root;
		Tree* parent;
		
		while(current) {
			if(current->data == key) // Need to insert distinct keys
				return;
			parent = current;
			current = current->data > key ? current->left : current->right;
		}

		if(parent->data > key)
			parent->left = node;
		else
			parent->right = node;
	}
}

void InOrderPrint(Tree* root) {
	if(!root)
		return;
	InOrderPrint(root->left);
	printf("%d-> ", root->data);
	InOrderPrint(root->right);
}

void ReplaceParentChildLink(Tree* parent, Tree* child, Tree* newChild) {
	if(!parent)
		return;
//	printf("%d - %d - %d\n", parent->data, child->data, newChild->data);
	if(parent->left == child)
		parent->left = newChild;
	else
		parent->right = newChild;
}

void DeleteNode(Tree** root, int key) {
	Tree* current = *root;
	Tree* parent;
	while(current->data != key) {
		parent = current;
		current = current->data > key ? current->left : current->right;
	}

	if(current->right) {
		Tree* rCurrent = current->right;
		Tree* rParent = current; // Imp step
        	while(rCurrent->left) {
                	rParent = rCurrent;
                	rCurrent = rCurrent->left;;
        	}

		ReplaceParentChildLink(parent, current, rCurrent);
		ReplaceParentChildLink(rParent, rCurrent, rCurrent->right);
		rCurrent->left = current->left;
		rCurrent->right = current->right;

		if(*root == current)
			*root = rCurrent;

	}
	else {

		if(*root == current)
			*root = current->left;
		
		ReplaceParentChildLink(*root, current, current->left);
	}
}

void main() {
	Tree* root = NULL;
	Insert(&root, 19);
        Insert(&root, 7);
        Insert(&root, 43);
        Insert(&root, 3);
        Insert(&root, 11);
        Insert(&root, 23);
        Insert(&root, 47);
        Insert(&root, 2);
        Insert(&root, 5);
        Insert(&root, 17);
        Insert(&root, 53);
        Insert(&root, 13);
        Insert(&root, 29);
        Insert(&root, 41);
        Insert(&root, 31);
	
	printf("InOrder Traversal :\n");
	InOrderPrint(root);
	printf("\n");
	
	DeleteNode(&root, 23);

	printf("InOrder Traversal after deletion:\n");
        InOrderPrint(root);
        printf("\n");
}

