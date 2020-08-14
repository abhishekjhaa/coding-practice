// Design a cache for a single system

/*
A linked list would allow easy purging of old data, by moving "fresh" items to the 
front. We could implement it to remove the last element of the linked list when the 
list exceeds a certain size. 

A hash-table/array allows efficient lookups of data, but it wouldn't ordinarily allow easy 
data purging. 

We create a linked list where a node is moved to the front every time it's 
accessed. This way, the end of the linked list will always contain the stalest information. 

In addition, we have a hash-table/array that maps from a query to the corresponding node 
in the linked list. This allows us to not only efficiently return the cached results, but also 
to move the appropriate node to the front of the list, thereby updating its "freshness." 
*/

#include<stdio.h>
#include<malloc.h>

// Implement Least Recently Used Cache

#define SIZE 6
#define ANSII 256

typedef struct Q {
	char data;
	struct Q* next;
} Q;

void Insert(char data, Q* cache[ANSII], Q** queue, Q** tail) {
	Q* node = malloc(sizeof(Q));
        node->data = data;
        node->next = *queue;
        if(!(*queue))
        	*tail = node;
        cache[data] = node;
        *queue = node;
}

void DeleteTail(Q* cache[ANSII], Q* queue, Q** tail) {
	while(queue && queue->next && queue->next != *tail)
		queue = queue->next;
	char characterToBeDeleted = (*tail)->data;
	*tail = queue;
	(*tail)->next = NULL;
	cache[characterToBeDeleted] =  NULL;
}

void MoveNodeToFrontOfQueue(Q* node, Q** queue, Q** tail) {
	if(*queue == node)
		return;
	Q* temp = *queue;
	while(temp->next != node)
		temp = temp->next;
	if(!(node->next)) {
		*tail = temp;
		(*tail)->next = NULL;
	}
	else
		temp->next = temp->next->next;
	node->next = *queue;
	*queue = node;
}

void Cache(char data, Q* cache[ANSII], Q** queue, Q** tail, int* cacheSize) {	
	if(*cacheSize > 0 && cache[data] && (cache[data])->data == data) {
        	printf("Cache Hit for '%c'. Moved the node to Front Of Queue\n", data);
		MoveNodeToFrontOfQueue(cache[data], queue, tail);
		//printf("Head Data = '%c' Tail Data = '%c'\n", (*queue)->data, (*tail)->data);
		return;
	}

	if(*cacheSize < SIZE) {
		printf("Inserted '%c' into cache\n", data);
		Insert(data, cache, queue, tail);
		*cacheSize += 1;
	}
	else {
		printf("Cache Miss for '%c'. Inserted into cache. Deleted '%c' from tail\n", data, (*tail)->data);
		DeleteTail(cache, *queue, tail);
		Insert(data, cache, queue, tail);
	}
}

void main() {
	char* stream = "fdfjsdfjweiofodskfsf";
	int numberOfANSIICharacters = ANSII;
	Q* cache[numberOfANSIICharacters];
	int count = 0;
	printf("Stream : ");
	while(count < ANSII)
		cache[count++] = NULL;
	Q* queue = NULL;
	Q* tail;
	count = 0;
	int cacheSize = 0;
	
	while(stream[count] != '\0')
		printf("%c", stream[count++]);
	printf("\n");
	
	count = 0;
	while(stream[count] != '\0')
		Cache(stream[count++], cache, &queue, &tail, &cacheSize);
}
