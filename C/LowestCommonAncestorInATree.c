#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Tree {
	char data;
	struct Tree* left;
	struct Tree* middle;
	struct Tree* right;
} Tree;

typedef struct List {
	char data;
	struct List* next;
} List;

void MakeTree(Tree** root, char leftData, char middleData, char rightData) {
	if(leftData != ' ') {
		(*root)->left = malloc(sizeof(Tree));
		(*root)->left->data = leftData;
	}
	if(rightData != ' ') {
		(*root)->right = malloc(sizeof(Tree));
		(*root)->right->data = rightData;
	}
	if(middleData != ' ') {
                (*root)->middle = malloc(sizeof(Tree));
                (*root)->middle->data = middleData;
        }
		
}

bool Compare(char data1, char data2, bool* pathFound) {
        if(data1 == data2) {
                *pathFound = true;
                return true;
        }
	
	return false;
}

void GetPath(Tree* root, char data1, List* list, bool* pathFound) {
	if(!root || root->data == ' ')
		return;
       	if(root->data == data1) {
		list->data = data1;
		list->next = NULL;
		return;
	}
	
	list->data = root->data;
	list->next = malloc(sizeof(List));

	if(!(*pathFound)) {
		GetPath(root->left, data1, list->next, pathFound);
		if(Compare(list->next->data, data1, pathFound))
			return;
	}

	if(!(*pathFound)) {
                GetPath(root->middle, data1, list->next, pathFound);
		if(Compare(list->next->data, data1, pathFound))
                	return;
	}

	if(!(*pathFound)) {
		GetPath(root->right, data1, list->next, pathFound);
		if(Compare(list->next->data, data1, pathFound))
                	return;
	}
}

char FindLCA(Tree* root, char data1, char data2) {
	List* list1 = malloc(sizeof(List));
	bool pathFound = false;
	GetPath(root, data1, list1, &pathFound);
	List* list2 = malloc(sizeof(List));
        pathFound = false;
        GetPath(root, data2, list2, &pathFound);
	List* prev = list2;
	while(list1->data == list2->data) {
                prev = list2;
		list2 = list2->next;
		list1 = list1->next;
        }

	return prev->data;
}

void main() {
	Tree* root = malloc(sizeof(Tree));
	root->data = 					'a';
	MakeTree(&root, 			'b', 		' ',		'c');
	MakeTree(&root->left, 	'd', 	' ',	'e');
        MakeTree(&root->right, 					'f', 	' ',	'g');
        MakeTree(&root->left->right, 	'h', 	'i',	'j');

	char result = FindLCA(root, 'd', 'j');
	printf("LCA is %c\n", result);
}


