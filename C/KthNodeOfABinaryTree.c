#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
        int size;
} Tree;

void MakeTree(Tree* root, int leftSize, int rightSize, int leftData, int rightData) {
        if(leftData != -1) {
                root->left = malloc(sizeof(Tree));
                root->left->data = leftData;
                root->left->size = leftSize;
        }
        if(rightData != -1) {
                root->right = malloc(sizeof(Tree));
                root->right->data = rightData;
                root->right->size = rightSize;
        }
}

void FindKthNode(Tree* root, int k) {
	int temp = k;
	while(root && k) {
		int leftSize = root->left ? root->left->size : 0;
		if(leftSize >= k)
			root = root->left;
		else if(leftSize == k - 1) {
			printf("k = %d & Kth Node is %d\n", temp, root->data);
			return;
		}
		else {
			root = root->right;
			k -= (leftSize + 1);
		}
	}
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data =                                    4;
        root->size = 7;
        MakeTree(root, 3, 3,                      1,                                              7);
        MakeTree(root->left, 0, 2,        -1,               2);
        MakeTree(root->left->right, 0, 1,               -1,    3);
        MakeTree(root->right, 2, 0,                                             6,                      -1);
        MakeTree(root->right->left, 1, 0,                                  5,       -1);
	
	int k = 3;
        FindKthNode(root, k);
}

