// Using Primm's Algorithm

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 5

int GetMinKey(int* key, bool* mstSet) {
	int count, min = INT_MAX, minIndex = 0;
	for(count = 0; count < V; count++) {
		if(key[count] < min && !mstSet[count]) {
			min = key[count];
			minIndex = count;
		}
	}

	return minIndex;
}

void PrintMST(int* parent, int graph[V][V]) {
	int i;
	for(i = 1; i < V; i++) {
		printf("%d -----> %d Edge Weight : %d\n", parent[i], i, graph[i][parent[i]]);
	}
}

void PrimMST(int graph[V][V]) {
	int key[V], parent[V], i, count, neighbour;
	bool mstSet[V];

	for(i = 0; i < V; i++) {
		key[i] = INT_MAX;
		parent[i] = -1;
		mstSet[i] = false;
	}

	key[0] = 0; // Starting point of Graph. Its key is 0

	for(count = 0; count < V - 1; count++) {
		int vertex = GetMinKey(key, mstSet); // Get Minimum key value which is not yet included in MST
		mstSet[vertex] = true; // Include it in MST
		
		for(neighbour = 0; neighbour < V; neighbour++) {
			if(graph[vertex][neighbour] && !mstSet[neighbour] && graph[vertex][neighbour] < key[neighbour]) {
				key[neighbour] = graph[vertex][neighbour];
				parent[neighbour] = vertex;
			}
		}
	}

	PrintMST(parent, graph);
}

void main() {
	int graph[V][V] =      {{0, 2, 0, 6, 0},
				{2, 0, 3, 8, 5},
				{0, 3, 0, 0, 7},
				{6, 8, 0, 0, 9},
				{0, 5, 7, 9, 0}};
	// Print the solution
	PrimMST(graph);
}
