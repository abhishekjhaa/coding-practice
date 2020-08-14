/*Write an algorithm to find the 'next' node (i.e., in-order successor) of a given node 
in a binary search tree. You may assume that each node has a link to its parent. */

#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	char data;
	struct Tree* left;
	struct Tree* right;
	struct Tree* parent;
} Tree;

void MakeTree(Tree** root) {
	(*root)->left = malloc(sizeof(Tree));
	(*root)->right = malloc(sizeof(Tree));

	(*root)->left->data = 'b';
	(*root)->right->data = 'c';

        (*root)->left->parent = (*root);
        (*root)->right->parent = (*root);


        (*root)->left->left = malloc(sizeof(Tree));
        (*root)->right->left = malloc(sizeof(Tree));

        (*root)->left->left->data = 'd';
        (*root)->right->left->data = 'f';

        (*root)->left->left->parent = (*root)->left;
        (*root)->right->left->parent = (*root)->right;

        (*root)->left->right = malloc(sizeof(Tree));
        (*root)->right->right = malloc(sizeof(Tree));

        (*root)->left->right->data = 'e';
        (*root)->right->right->data = 'g';

        (*root)->left->right->parent = (*root)->left;
        (*root)->right->right->parent = (*root)->right;

        (*root)->left->right->left = malloc(sizeof(Tree));
        (*root)->left->right->right = malloc(sizeof(Tree));

        (*root)->left->right->left->data = 'h';
        (*root)->left->right->right->data = 'i';

        (*root)->left->right->left->parent = (*root)->left->right;
        (*root)->left->right->right->parent = (*root)->left->right;

}

void DoInOrderTraversal(Tree* root) {
	if(!root)
		return;
	DoInOrderTraversal(root->left);
	printf("%c -> ", root->data);
        DoInOrderTraversal(root->right);	
}

void GetNextNode(Tree* node) {
	if(!node) {
		return;
	}

	if(node->right) {
		Tree* nodeRight = node->right;   	
		while(nodeRight->left) {
			nodeRight = nodeRight->left;
		}

	     	printf("Next Node of %c is %c \n", node->data, nodeRight->data);
	}
	else {
        	Tree* current = node;
		Tree* parent = node->parent;
		while(parent && current == parent->right) {
			current = parent;
			parent = parent->parent;
		}

		if(parent)
                	printf("Next Node of %c is %c \n", node->data, parent->data);
		else
			printf("You have picked last Node %c \n", node->data);
	}
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 'a';
	MakeTree(&root);
	printf("InOrder Traversal : ");
	DoInOrderTraversal(root);
	printf("\n");
	GetNextNode(root->left->right);
        GetNextNode(root->left->left);
        GetNextNode(root->right->right);
        GetNextNode(root->right->left);
        GetNextNode(root->left);
        GetNextNode(root->right);
        GetNextNode(root->left->right->left);
        GetNextNode(root->left->right->right);
        GetNextNode(root);
}
