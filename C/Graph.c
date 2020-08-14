#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Edge {
	struct Vertex* connectsTo;
	struct Edge* next;
} Edge;

typedef struct Vertex {
	char data;
	bool isVisited;
	int maxDistance;
	struct Edge* edges;
	struct Vertex* next;
} Vertex;

typedef struct List {
	Vertex* vertex;
	struct List* next;
} List;

void MakeVertex(Vertex** vertex, char data) {
	Vertex* node = malloc(sizeof(Vertex));
        node->data = data;
       	node->isVisited = false;
        node->maxDistance = 1;
	node->edges = NULL;

	*vertex = node;
}

void ConnectEdges(Vertex* vertex, Vertex* connectingVertex) {
	Edge* edge = vertex->edges;
	while(edge && edge->next)
		edge = edge->next;
	Edge* temp = malloc(sizeof(Edge));
        temp->connectsTo = connectingVertex;
	if(!edge)
		vertex->edges = temp;
	else
		edge->next = temp;
}

void AddVertices(Vertex** initialVertex) {
	MakeVertex(initialVertex, 'A');
        MakeVertex(&(*initialVertex)->next, 'B');
        MakeVertex(&(*initialVertex)->next->next, 'C');
        MakeVertex(&(*initialVertex)->next->next->next, 'D');
        MakeVertex(&(*initialVertex)->next->next->next->next, 'E');
        MakeVertex(&(*initialVertex)->next->next->next->next->next, 'F');
}

void AddEdges(Vertex* initialVertex) {
	ConnectEdges(initialVertex, initialVertex->next);
        ConnectEdges(initialVertex, initialVertex->next->next->next);
        ConnectEdges(initialVertex->next->next, initialVertex->next->next->next->next->next);
        ConnectEdges(initialVertex->next->next->next, initialVertex->next->next->next->next);
        ConnectEdges(initialVertex->next->next->next, initialVertex->next);
        ConnectEdges(initialVertex->next->next->next->next, initialVertex->next);
        ConnectEdges(initialVertex->next->next->next->next->next, initialVertex->next->next);
}

void AddVertexToList(Vertex* vertex, List** list) {
	List* node = malloc(sizeof(List));
	node->vertex = vertex;
	node->next = *list;
	*list = node;
}

void DFS(Vertex* vertex, List** list) {
	vertex->isVisited = true;
	Edge* edge = vertex->edges;
	while(edge) {
		if(!edge->connectsTo->isVisited)
			DFS(edge->connectsTo, list);
		edge = edge->next;			
	}

	AddVertexToList(vertex, list);
}

void BuildTopologiocalOrdering(Vertex* vertex, List** list) {
	while(vertex) {
		if(!vertex->isVisited)
			DFS(vertex, list);
		vertex = vertex->next;
	}
}

int Max(int a, int b) {
	return a > b ? a : b;
}

int FindLongestPath(List* list) {
	int maxDistance = 0;
	while(list) {
		Vertex* vertex = list->vertex;
		maxDistance = Max(maxDistance, vertex->maxDistance);
		Edge* edge = vertex->edges;
		while(edge) {
			Vertex* ver = edge->connectsTo;
			ver->maxDistance = Max(ver->maxDistance, vertex->maxDistance + 1);
			edge = edge->next;
		}

		list = list->next;
	}

	return maxDistance;
}

int FindLargestNumberTeams(Vertex* initialVertex) {
	List* list = NULL;
	BuildTopologiocalOrdering(initialVertex, &list);
	return FindLongestPath(list);
}

void main() {
	Vertex* initialVertex;
	AddVertices(&initialVertex);
	AddEdges(initialVertex);
	
	int result = FindLargestNumberTeams(initialVertex);
	printf("%d\n", result);
}
