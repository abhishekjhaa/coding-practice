#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
} Tree;

void MakeTree(Tree* root, int leftData, int rightData) {
        if(leftData != -1) {
                root->left = malloc(sizeof(Tree));
                root->left->data = leftData;
        }
        if(rightData != -1) {
                root->right = malloc(sizeof(Tree));
                root->right->data = rightData;
        }
}

int FindNonKBalancedNode(Tree* root, int k, Tree** nonKBalancedNode) {
	if(!root)
		return 0;

	int left = FindNonKBalancedNode(root->left, k, nonKBalancedNode);
	int right = FindNonKBalancedNode(root->right, k, nonKBalancedNode);
	if((left - right > k || left - right < -k) && *nonKBalancedNode == NULL)
		*nonKBalancedNode = root;
		
	return left + right + 1;
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data =                                    314;
        MakeTree(root,                          6,                                              6);
        MakeTree(root->left,            271,               561);
        MakeTree(root->left->left, 28,       0);
        MakeTree(root->left->right,                     -1,    3);
        MakeTree(root->left->right->right,                  17,   -1);
        MakeTree(root->right,                                                   2,                      271);
        MakeTree(root->right->left,                                        -1,       1);
        MakeTree(root->right->left->right,                                      401,     257);
        MakeTree(root->right->left->right->left,                             -1,     641);
        MakeTree(root->right->right,                                                            -1,              28);

	int k = 3;
	Tree* nonKBalancedNode = NULL;
        FindNonKBalancedNode(root, k, &nonKBalancedNode);
	if(nonKBalancedNode)
		printf("Non K Balanced Tree Found at Node %d\n", nonKBalancedNode->data);
	else
		printf("No such Node found\n");
}

