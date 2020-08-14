#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
} Tree;

typedef struct List {
        Tree* node;
        struct List* next;
} List;

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

void RangeQuery(Tree* root, int low, int high, List** list, List** head) {
	if(!root)
		return;
	RangeQuery(root->left, low, high, list, head);

	if(root->data > low && root->data < high) {
		List* temp = malloc(sizeof(List));
		temp->node = root;
		temp->next = NULL;
		printf("%d\n", root->data);
		if(*list)
			(*list)->next = temp;
		else
			*head = temp;			
		*list = temp;
	}

	RangeQuery(root->right, low, high, list, head);
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
	Insert(&root, 37);
        Insert(&root, 53);
        Insert(&root, 13);
        Insert(&root, 29);
        Insert(&root, 41);
        Insert(&root, 31);

	List* list = NULL;
	List* head;
	int lowerBound = 20;
	int upperBound = 40;
	RangeQuery(root, lowerBound, upperBound, &list, &head);
	while(head) {
		printf("%d-> ", head->node->data);
		head = head->next;
	}
	printf("\n");
}
