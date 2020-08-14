#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
} Tree;

typedef struct List {
	Tree* treeNode;
	struct List* next; 
} List;

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

void MakeListOfLeafNodes(Tree* leafNode, List** list) {
	List* temp = malloc(sizeof(List));
	temp->treeNode = leafNode;
	temp->next = NULL;
	if(!(*list)) {
		temp->next = *list;
		*list = temp;
	}
	else {
		List* head = *list;
		while((*list)->next) {
			*list = (*list)->next;
		}
		(*list)->next = temp;
		*list = head;
	}
}

void InOrderTraverse(Tree* root, List** list) {
	if(!root)
		return;

	if(!(root->left) && !(root->right)) {
		MakeListOfLeafNodes(root, list);
		return;
	}

	InOrderTraverse(root->left, list);
	InOrderTraverse(root->right, list);
}

void AddLeftNodesToFrontOfList(Tree* root, List** list) {
	if(!root->left)
		return;
	AddLeftNodesToFrontOfList(root->left, list);
	List* temp = malloc(sizeof(List));
        temp->treeNode = root;
        temp->next = *list;
	*list = temp;
}

void AddRightNodesToBackOfList(Tree* root, List** list) {
        if(!root->right)
                return;
        AddRightNodesToBackOfList(root->right, list);
        List* temp = malloc(sizeof(List));
        temp->treeNode = root;
     	temp->next = NULL;
	List* head = *list;
        while((*list)->next) {
		*list = (*list)->next;
        }
        (*list)->next = temp;
        *list = head;

}

void LeftBoundaryTree(Tree* root, bool isBoundary) {
	if(root) {
		if(isBoundary || (!root->left && !root->right))
			printf("%d-> ", root->data);
		LeftBoundaryTree(root->left, isBoundary);
		LeftBoundaryTree(root->right, isBoundary && !root->left);
	}
}

void RightBoundaryTree(Tree* root, bool isBoundary) {
        if(root) {
		RightBoundaryTree(root->right, isBoundary);
        	RightBoundaryTree(root->left, isBoundary && !root->right);
	
		if(isBoundary || (!root->left && !root->right))
         	       printf("%d-> ", root->data);
	}
}


void ExteriorBinaryTree(Tree* root) {
	if(root) {
		printf("%d-> ", root->data);
		LeftBoundaryTree(root->left, true);
		RightBoundaryTree(root->right, true);
	}
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
	List* list = NULL;	
	InOrderTraverse(root, &list);
	AddLeftNodesToFrontOfList(root, &list);
	AddRightNodesToBackOfList(root->right, &list);
	printf("Circumference Nodes of Binary Tree : \n");
	while(list) {
		printf("%d-> ", list->treeNode->data);
		list = list->next;
	}
	printf("\n");

	//2nd Approach
	ExteriorBinaryTree(root);
	printf("\n");
}
