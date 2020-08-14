#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	int data;
	char id;
	struct Tree* left;
	struct Tree* right;
} Tree;

void AddNode(Tree** root, int data, char id) {
	*root = malloc(sizeof(Tree));
        (*root)->data = data;
        (*root)->id = id;
        (*root)->left = NULL;
        (*root)->right = NULL;
}

void MakeTree(Tree** root) {
        *root = malloc(sizeof(Tree));
        (*root)->data = 108;
        (*root)->id = 'a';
	(*root)->left = NULL;
	(*root)->right = NULL;


	AddNode(&(*root)->left, 108, 'b');
        AddNode(&(*root)->right, 285, 'g');
        AddNode(&(*root)->left->left, -10, 'c');
        AddNode(&(*root)->left->right, 108, 'f');
        AddNode(&(*root)->left->left->left, -14, 'd');
        AddNode(&(*root)->left->left->right, 2, 'e');
        AddNode(&(*root)->right, 285, 'g');
        AddNode(&(*root)->right->left, 243, 'h');
        AddNode(&(*root)->right->right, 285, 'i');
        AddNode(&(*root)->right->right->right, 401, 'j');
}

void InOrderTraverse(Tree* root) {
	if(!root)
		return;
	InOrderTraverse(root->left);
	printf("(%d, %c)-> ", root->data, root->id);
	InOrderTraverse(root->right);
}

char FindFirstOccurenceOf(Tree* root, int k) {
	if(!root)
		return;
	if(root->data == k) {
		char n = FindFirstOccurenceOf(root->left, k);
		return n ? n : root->id;
	}

	return FindFirstOccurenceOf(k > root->data ? root->right : root->left, k);
}

char IterativeFindFirstOccurenceOf(Tree* root, int k) {
        if(!root)
                return;
	char n;
	while(root) {
		if(root->data > k)
			root = root->left;
		else if(root->data < k)
			root = root->right;
		else {
			n = root->id;
                	root = root->left;		
		}
	}
	
	return n;
}


void main() {
	Tree* root = NULL;
	MakeTree(&root);
	InOrderTraverse(root);
	printf("\n");
	
	int k = 108;
	char result = FindFirstOccurenceOf(root, k);
	printf("Recursive : First Occurence of %d is at node %c\n", k, result);
	
	k = 285;
        result = FindFirstOccurenceOf(root, k);
        printf("Recursive : First Occurence of %d is at node %c\n", k, result);

	k = 108;
        result = IterativeFindFirstOccurenceOf(root, k);
        printf("Iterative : First Occurence of %d is at node %c\n", k, result);

	k = 285;
        result = IterativeFindFirstOccurenceOf(root, k);
        printf("Iterative : First Occurence of %d is at node %c\n", k, result);
}
