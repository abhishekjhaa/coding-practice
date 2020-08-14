#include<stdio.h>
#include<malloc.h>

#define SIZE 15

typedef struct List {
	int data;
	struct List* next;
} List;

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

void Add(List** tail, int data) {
	List* node = malloc(sizeof(List));
	node->data = data;
	node->next = NULL;
	if(*tail)
		(*tail)->next = node;

	*tail = node;	
}

void BuildSortedList(List** list) {
	Add(list, 1);
	List* head = *list;
	int i;
	for(i = 2; i <= SIZE; i++)
		Add(list, i);
	*list = head;
}

Tree* BuildBalancedBST(List** list, int start, int end) {
	if(start < end) {
		Tree* node = malloc(sizeof(Tree)); // create empty node for each of the positions.
		int mid = start + (end - start) / 2;
		node->left = BuildBalancedBST(list, start, mid);
		node->data = (*list)->data;
		*list = (*list)->next; // Imp Step
		node->right = BuildBalancedBST(list, mid + 1, end);
		return node;
	}

	return NULL;
}

void InOrderTraverse(Tree* root) {
        if(!root)
                return;
        InOrderTraverse(root->left);
        printf("%d-> ", root->data);
        InOrderTraverse(root->right);
}


void main() {
	List* list = NULL;
	BuildSortedList(&list);
	Tree* result = BuildBalancedBST(&list, 0, SIZE);
	InOrderTraverse(result);
	printf("\n");
}
