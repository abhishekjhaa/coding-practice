#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

#define ALPHABETS 26

typedef struct Trie {
	bool data; 
	struct Trie* array[ALPHABETS]; 
} Trie;

void CreateANewNode(Trie** node, bool data) {
	Trie* temp = malloc(sizeof(Trie));
	temp->data = data;
	*node = temp;
}

void Insert(Trie* root, char* str) {
	int i = 0;
	bool data;
	while(str[i] != '\0') {
		if(root->array[str[i] - 'a'] == NULL) {
			if(str[i + 1] == '\0')
				data = true;
			else
				data = false;
			CreateANewNode(&(root->array[str[i] - 'a']), data);
		}
		else if(root->array[str[i] - 'a']->data == str[i]) {
			if(str[i + 1] == '\0')
				root->data = true;
			
		}

		root = root->array[str[i] - 'a'];
		i++;
	}

	printf("Inserted '%s'\n", str);
}

void Search(Trie* root, char* str) {
	int i = 0;
	while(str[i] != '\0') {
		if(root->array[str[i] - 'a']) {
			if(!root->array[str[i] - 'a']->data && str[i + 1] == '\0') {
				printf("'%s' is in trie but not a valid word\n", str);
				return;
			}
			root = root->array[str[i] - 'a'];
		}
		else {
			printf("'%s' not found in trie\n", str);
			return;
		}

		i++;
	}

	printf("'%s' is found in trie\n", str);
}

void main() {
	Trie* root = malloc(sizeof(Trie));
	root->data = false;
	
	char* data = "there";
	Insert(root, data);

	data = "their";
	Insert(root, data);

	data = "answer";
        Insert(root, data);

	data = "any";
        Insert(root, data);

	data = "bye";
        Insert(root, data);

	data = "the";
	Search(root, data);

	data = "these";
        Search(root, data);

	data = "any";
        Search(root, data);

	data = "thaw";
        Search(root, data);

	data = "by";
        Search(root, data);

	data = "a";
        Search(root, data);
}
