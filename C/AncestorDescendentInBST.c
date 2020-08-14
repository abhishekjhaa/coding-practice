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

bool CheckAncestor(Tree* descendent, Tree* ancestor) {
        while(ancestor && descendent) {
                if(ancestor->data == descendent->data)
                        return true;
                else if(ancestor->data < descendent->data)
			ancestor = ancestor->right;
                else
		        ancestor = ancestor->left;
        }

        return false;
}

bool CheckAncestorDescendent(Tree* m , Tree* s, Tree* r) {
	// lets 1st assume, s is the ancestor & r is the descendent of m
	// if the above assumption is wrong then assume r is the ancestor and s is the descendant
	// if both assumptions fail then m doesn't lie between s & r.
	return CheckAncestor(m, s) ? CheckAncestor(r, m) : (CheckAncestor(m, r) && CheckAncestor(s, m));
}

Tree* GetNode(Tree* root, int key) {
	while(root) {
		if(root->data == key)
			return root;
		else if(root->data < key)
			root = root->right;
		else
			root = root->left;
	}

	return NULL;
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

	Tree* m = GetNode(root, 23); // keynode, check if it lies between s & r
	Tree* s = GetNode(root, 19); // can be either ancestor/descendent of m
	Tree* r = GetNode(root, 37); // can be either ancestor/descendent of m

	if(CheckAncestorDescendent(m , s, r))
                printf("Key %d is found between %d & %d\n", m->data, s->data, r->data);
        else
                printf("Key %d doesn't lie between %d & %d\n", m->data, s->data, r->data);

}
