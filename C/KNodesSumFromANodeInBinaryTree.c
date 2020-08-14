////http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree; 

Tree* AddNode(int data) {
	Tree* node =  malloc(sizeof(Tree));
        node->data = data;
	node->left =  NULL;
	node->right =  NULL;
	return node;
}

Tree* MakeTree(Tree* root) {
	root = AddNode(10);
	root->left = AddNode(12);
	root->right = AddNode(15);
	root->left->left = AddNode(18);
	root->left->right = AddNode(20);
	root->right->left = AddNode(25);
	root->right->right = AddNode(30);
	root->left->right->left = AddNode(35);
	root->left->right->right = AddNode(40);
	root->left->right->left->left = AddNode(45);
	return root;
}

void InOrder(Tree* root) {
	if(!root)
		return;
	InOrder(root->left);
	printf("%d, ", root->data);
	InOrder(root->right);
}

void GetDescendents(Tree* root, int k, int* sum) {
	if(!root || k < 0)
		return;
	if(k == 0) {
		*sum += root->data;
		return;
	}

	GetDescendents(root->left, k - 1, sum);
	GetDescendents(root->right, k - 1, sum);
}

int FindSum(Tree* root, int N, int k, int* sum) {
	if(!root)
		return -1;

	if(root->data == N) {
		GetDescendents(root, k, sum);
		return 0;
	}

	int l = FindSum(root->left, N, k, sum);
	if(l != -1) {
		if(k == l + 1) {
			*sum += root->data;
		}
		else {
			GetDescendents(root->right, k - (l + 2), sum);
		}

		return l + 1;
	}
        
	int r = FindSum(root->right, N, k, sum);
	if(r != -1) {
               if(k == r + 1) {
                        *sum += root->data;
                }
                else {
                        GetDescendents(root->left, k - (r + 2), sum);
                }

                return r + 1;
	}
	
	return -1;
}

int GetSum(Tree* root, int N, int k) {
	int sum = 0, level = 1;
	FindSum(root, N, k, &sum);
	return sum;
}

void main() {
	Tree* root =  NULL;
	root = MakeTree(root);
	InOrder(root);
	printf("\n");
	int N = 20, k = 2;
	int sum = GetSum(root, N, k);
	printf("%d\n", sum);
}
