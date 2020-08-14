#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
} Tree;

typedef struct List {
        struct Tree* node;
        struct List* next;
} List;

static int count = 0;

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

void Enqueue(List** q, Tree* root) {
	List* item = malloc(sizeof(List));
	item->node = root;
	item->next = NULL;
	if(!(*q)) {
		*q = item;
	}
	else {
		(*q)->next = item;
		*q = (*q)->next;
	}
	
}

void Dequeue(List** head) {
	*head = (*head)->next;
}

void TraverseLevelOrder(Tree* root) {
	List* q = NULL;
	Enqueue(&q, root);
	List* head = q;
	while(head) {
		printf("%d-> ", head->node->data);
		if(head->node->left)
			Enqueue(&q, head->node->left);
		if(head->node->right)
                        Enqueue(&q, head->node->right);
		Dequeue(&head);
	}
}

void main() {
	Tree* root = malloc(sizeof(Tree));
        root->data =                            	314;
        MakeTree(root,               		6,                  				6);
        MakeTree(root->left, 		271,               561);
	MakeTree(root->left->left, 28,       0);
        MakeTree(root->left->right,         		-1,    3);
	MakeTree(root->left->right->right,                  17,   -1);
        MakeTree(root->right,                           			2,  			271);
	MakeTree(root->right->left,                                        -1,       1);
	MakeTree(root->right->left->right,                                      401,     257);
	MakeTree(root->right->left->right->left,                             -1,     641);
        MakeTree(root->right->right,                                                   		-1,              28);
	
	TraverseLevelOrder(root);
	printf("\n");
}
