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

void ReverseInOrderTraverse(Tree* root, int* k) {
	if(root && *k > 0) {
		ReverseInOrderTraverse(root->right, k);
		if(*k > 0) {
			printf("%d, ", root->data);
			(*k)--;
			ReverseInOrderTraverse(root->left, k);
		}
	}
}

void PreOrder(Tree* root) {
	if(!root)
		return;
	printf("%d, ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
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

	int k = 4;
      	printf("Largest %d elements are : ", k);
        ReverseInOrderTraverse(root, &k);
        printf("\n");
	PreOrder(root);
	printf("\n");
}
