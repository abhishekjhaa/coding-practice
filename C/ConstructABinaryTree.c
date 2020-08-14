#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

Tree* ConstructTreeRecursively(int* preOrderStart, int* preOrderEnd, int* inOrderStart, int* inOrderEnd) {
	Tree* node = malloc(sizeof(Tree));
	node->data = preOrderStart[0];

	if(preOrderStart == preOrderEnd && inOrderStart == inOrderEnd && preOrderStart == inOrderStart)
		return node;
	
	int* rootInOrder = inOrderStart;
	while(rootInOrder <= inOrderEnd && *rootInOrder != node->data)
		rootInOrder++;
	int leftLength = rootInOrder - inOrderStart;
	int rightLength = inOrderEnd - rootInOrder;
	if(leftLength > 0)
	        node->left = ConstructTreeRecursively(preOrderStart + 1, preOrderStart + leftLength, inOrderStart, inOrderStart + leftLength - 1);
	if(rightLength > 0)
		node->right = ConstructTreeRecursively(preOrderStart + leftLength + 1, preOrderEnd, inOrderStart + leftLength + 1, inOrderEnd);

	return node;
}

Tree* ConstructTree(int* preOrder, int* inOrder, int length) {
	return ConstructTreeRecursively(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

void PreOrderTraversal(Tree* root) {
	if(!root)
		return;
	printf("%d ", root->data);
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}

void InOrderTraversal(Tree* root) {
        if(!root)
                return;
        InOrderTraversal(root->left);
        printf("%d ", root->data);
	InOrderTraversal(root->right);
}


void main() {
	int preOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,8,6};
	
	int length = 8;
	int i;
	for(i = 0; i < length; i++) {
                printf("%d ", preOrder[i]);
        }
        printf("\n");

	for(i = 0; i < length; i++) {
		printf("%d ", inOrder[i]);
	}
	printf("\n");

	Tree* root = ConstructTree(preOrder, inOrder, length);
	printf("PreOrder Traversal\n");
	PreOrderTraversal(root);
	printf("\nInOrder Traversal\n");
	InOrderTraversal(root);
	printf("\n");
}
