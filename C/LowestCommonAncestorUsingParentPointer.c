#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
	struct Tree* parent;
} Tree;

void MakeTree(Tree* root, int leftData, int rightData) {
	if(leftData != 0) {
		root->left = malloc(sizeof(Tree));
		root->left->data = leftData;
		root->left->parent = root;
	}
	if(rightData != 0) {
		root->right = malloc(sizeof(Tree));
		root->right->data = rightData;
		root->right->parent = root;
	}
}

int FindDepth(Tree* node) {
	int count = 0;
	while(node->parent) {
		count++;
		node = node->parent;
	}
	
	return count;
}

void ForwardNodeByDiff(Tree** node, int diff) {
	while(diff > 0) {
		*node = (*node)->parent;
                diff--;
        }
}

Tree* FindLCA(Tree* node1, Tree* node2) {
	int depth1 = FindDepth(node1);
	int depth2 = FindDepth(node2);
	
	int diff = depth1 > depth2 ? depth1 - depth2 : depth2 - depth1;
	if(depth1 > depth2) {
		ForwardNodeByDiff(&node1, diff);
	}
	else {
		ForwardNodeByDiff(&node2, diff);
	}

	while(node1 != node2) {
		node1 = node1->parent;
		node2 = node2->parent;
	}

	return node1;
}

// It assumes all the node data have different values
Tree* FindLCAUsingArray(Tree* node1, Tree* node2) {
	Tree* array[150];
	int count = 0;
	while(count < 150) {
		array[count] = NULL;
		count++;
	}
	while(node1 || node2) {
		if(node1) {
			if(array[node1->data] != NULL)
				return node1;
			else
				array[node1->data] = node1;
			node1 = node1->parent;
		}
		if(node2) {
                        if(array[node2->data] != NULL)
                                return node2;
                        else
                                array[node2->data] = node2;
			node2 = node2->parent;
                }
	}
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 					81;
	root->parent = NULL;
	MakeTree(root, 			70, 				90);
	MakeTree(root->left, 	50, 		75);
        MakeTree(root->right, 					85, 		110);
        MakeTree(root->left->right, 	72, 		78);

	Tree* result = FindLCA(root->left->left, root->left->right->right);
	printf("LCA is : %d\n", result->data);
	result = FindLCAUsingArray(root->left->left, root->left->right->right);
	printf("LCA is : %d\n", result->data);
}


