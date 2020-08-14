#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
} Tree;

static int count = 0;

void MakeTree(Tree* root, int leftData, int rightData) {
        root->left = malloc(sizeof(Tree));
        root->right = malloc(sizeof(Tree));
        root->left->data = leftData;
        root->right->data = rightData;
}

void ByRotation(Tree* root, Tree** head) {
	Tree* prevNode = NULL;
	Tree* tempHead = NULL;
	while(root) {
		while(root->left) {
			Tree* temp = root->left;
			root->left = temp->right;
			temp->right = root;
			root = temp;
			if(prevNode)
				prevNode->right = root;
		}

		if(!(*head)) {
			*head = root;
			tempHead = root;
		}
		prevNode = root;
		if(root->right)
			root = root->right;
		else {
			root->left = tempHead;
			break;
		}
		while(tempHead->right != root) {
			tempHead->right->left = tempHead;
			tempHead = tempHead->right;
		}
	}
}

void main() {
        Tree* root = malloc(sizeof(Tree));
        root->data =                    8;
        MakeTree(root,            6,             10);
        MakeTree(root->left, 5,       7);
        MakeTree(root->right,                  9,   11);
	Tree* head = NULL;
        ByRotation(root, &head);
	Tree* reverseHead;
	while(head) {
      		printf("%d ", head->data);
		reverseHead = head;
		head = head->right;
	}
	printf("\n");
	while(reverseHead) {
                printf("%d ", reverseHead->data);
                reverseHead = reverseHead->left;
        }
        printf("\n");
}

