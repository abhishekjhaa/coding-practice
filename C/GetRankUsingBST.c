/* Cracking the Coding Interview Q 11.8
Imagine you are reading in a stream of integers. Periodically, you wish to be able to 
look up the rank of a number x (the number of values less than or equal to x). Implement 
the data structures and algorithms to support these operations. That is, implement 
the method track (int x), which is called when each number is generated, 
and the method getRankOfNumber(int x), which returns the numberofvalues 
less than or equal tox (not including x itself). */

#include<stdio.h>
#include<malloc.h>

typedef struct Tree {
	int data;
	int leftSize;
	struct Tree* left;
	struct Tree* right;	
} Tree;

void Track(Tree** root, int data) {
	if(!(*root)) {
		*root = malloc(sizeof(Tree));
		(*root)->data = data;
		(*root)->leftSize = 0;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if((*root)->data >= data) {
		(*root)->leftSize += 1;
		Track(&(*root)->left, data);
	}
	else
		Track(&(*root)->right, data);

	return;
}

int GetRankOf(Tree* root, int data) {
	// We are returning -1 incase the data doesn't exists in the tree
	if(!root)
		return -1;
	if(root->data == data)
		return root->leftSize;
	else if(root->data > data)
		return root->left == NULL ? -1 : GetRankOf(root->left, data);
	else {
		int rightRank = root->right == NULL ? -1 : GetRankOf(root->right, data);
		return rightRank == -1 ? -1 : root->leftSize + 1 + rightRank; // Imp Step
	}
}

void main() {
	int stream[] = {20, 15, 25, 10, 23, 5, 13, 24};
	int i = 0;
	Tree* root = NULL;
	while(stream[i]) {
		Track(&root, stream[i++]);
	}

	while(stream[--i]) {
		int result = GetRankOf(root, stream[i]);
		printf("Number %d has rank of %d\n", stream[i], result);
	}
	
	int data = 100;
	int result = GetRankOf(root, data);
	if(result == -1)
		printf("No such data = %d is found\n", data);
	else
		printf("Data = %d is found with rank %d \n", data, result);

	data = 4;
        result = GetRankOf(root, data);
        if(result == -1)
                printf("No such data = %d is found\n", data);
        else
                printf("Data = %d is found with rank %d \n", data, result);

}
