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

void GetMirroredTree(Tree* root, int size) {
	Tree* arrayTree[size];
	int count = 1;	
	arrayTree[0] = root;
	int i;
	for(i = 0; i < size; i++)
		if(arrayTree[i]) {
			printf("%d\n", (arrayTree[i])->data);
			Tree* temp = (arrayTree[i])->left;
			(arrayTree[i])->left = (arrayTree[i])->right;
			(arrayTree[i])->right = temp;
			if((arrayTree[i])->left)
				printf("%d\t", (arrayTree[i])->left->data);
			if((arrayTree[i])->right)
				printf("%d\n", (arrayTree[i])->right->data);
			arrayTree[count++] = (arrayTree[i])->left;
			arrayTree[count++] = (arrayTree[i])->right;
		}
}

void GetMirroredTreeUsingRecursion(Tree* root) {
	if(!root)
		return;
	if(!root->left && !root->right)
		return;
	Tree* temp = root->left;
	root->left = root->right;
	root->right = temp;
	if(root->left)
		GetMirroredTreeUsingRecursion(root->left);
        if(root->right)
                GetMirroredTreeUsingRecursion(root->right);

}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data =                    8;
        MakeTree(root,            6,             10);
        MakeTree(root->left, 5,       7);
        MakeTree(root->right,                  9,   11);
	int size = 7;
	GetMirroredTree(root, size);
	GetMirroredTreeUsingRecursion(root);
	printf("------------If above and below pattern are same then recursion succeded\n");
	GetMirroredTree(root, size);
}
