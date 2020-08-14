#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

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

Tree* FindFirstLargerThanK(Tree* root, int k) {
	Tree* first = NULL;
	bool foundK = false;
	while(root) {
		if(root->data == k) {
			foundK = true;
			root = root->right;
		}
		else if(root->data > k) {
//			printf("%d, k = %d\n", root->data, k);
			first = root; // Imp step.
			root = root->left;
		}
		else
			root = root->right;
	}

	return foundK ? first : NULL;
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
	
	int k = 23;
        Tree* result = FindFirstLargerThanK(root, k);
        printf("Next node of %d is %d\n", k, result->data);
}

