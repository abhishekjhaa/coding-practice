#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
        int data;
        struct Tree* left;
        struct Tree* right;
} Tree;

void MakeTree(Tree* root, int leftData, int rightData) {
        if(leftData != 0) {
		root->left = malloc(sizeof(Tree));
		root->left->data = leftData;
	}
	if(rightData != 0) {
        	root->right = malloc(sizeof(Tree));
		root->right->data = rightData;
	}
        root->left->data = leftData;
}

void InOrderTraversal(Tree* root, Tree** node) {
	if(!root)
		return;
	InOrderTraversal(root->left, node);
	root->left = *node; // Imp Step.
	if(*node) {
		(*node)->right = root;
	}
	*node = root;
	InOrderTraversal(root->right, node);
}

Tree* PrintList(Tree* list, int* count) {
	Tree* head;
	if(list->left) {
		while(list) {
                	printf("%d ", list->data);
                	head = list;
                	list = list->left;
			(*count)++;
        	}
	}
	else {
		while(list) {
                	printf("%d ", list->data);
                	head = list;
                	list = list->right;
			(*count)++;
        	}
	}
	
	printf("\n");
	return head;
}

Tree* MergeList(Tree* list1, Tree* list2) {
	Tree* head;
	if(list1->data < list2->data)
		head = list1;
	else
		head = list2;
	while(list1 && list2) {
		if(list1->data < list2->data) {
			while(list1->right && list1->right->data < list2->data)
				list1 = list1->right;
			Tree* temp1 = list1->right;
			list1->right = list2;
			list2->left = list1;
			Tree* temp2 = list2->right;
			list2->right = temp1;
			list2 = temp2;
			list1 = temp1;
		}
		else {
			Tree* temp = list1;
			list1 = list2;
			list2 = temp;
		}
	}

	if(list2) {
		list1->right = list2;
		list2->left = list1;
	}
	
	return head;
}

Tree* MakeBST(Tree** list, int start, int end) {
	if(start < end) {
		Tree* node = malloc(sizeof(Tree));
		int mid = start + (end - start)/2;
		node->left = MakeBST(list, start, mid);
		node->data = (*list)->data;
		*list = (*list)->right;
		node->right = MakeBST(list, mid + 1, end);
		return node;
	}
	
	return NULL;
}

void PrintInOrder(Tree* root) {
	if(!root)
		return;
	PrintInOrder(root->left);
	printf("%d-> ", root->data);
	PrintInOrder(root->right);
}

void main() {
	Tree* root1 = malloc(sizeof(Tree));
        root1->data =                    17;
        MakeTree(root1,            5,             23);
        MakeTree(root1->left, 2,       11);
       	
	Tree* node1 = NULL;
	int count1 = 0;
	InOrderTraversal(root1, &node1);
	Tree* head1 =  PrintList(node1, &count1);

	Tree* root2 = malloc(sizeof(Tree));
        root2->data =                    13;
        MakeTree(root2,            7,             19);
        MakeTree(root2->left, 3,       0);
        
        Tree* node2 = NULL;
	int count2 = 0;
        InOrderTraversal(root2, &node2);
        Tree* head2 =  PrintList(node2, &count2);

	Tree* mergedList = MergeList(head1, head2);
	int lengthOfList = count1 + count2;
	
	printf("%d\n", lengthOfList);

	
	Tree* result = MakeBST(&mergedList, 0, lengthOfList);
	
	PrintInOrder(result);
	printf("\n");
}
