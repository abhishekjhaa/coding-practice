// Using Dijsktra's Algorithm

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 9

int GetMinKey(int* key, bool* sptSet) {
	int count, min = INT_MAX, minIndex = 0;
	for(count = 0; count < V; count++) {
		if(key[count] < min && !sptSet[count]) {
			min = key[count];
			minIndex = count;
		}
	}

	return minIndex;
}

void PrintSPT(int* parent, int graph[V][V], int* key) {
	int i;
	for(i = 0; i < V; i++) {
		printf("%d -----> %d Distance from Source : %d Edge Weight : %d\n", parent[i], i, key[i], graph[i][parent[i]]);
	}
}

void DijsktraSPT(int graph[V][V], int source) {
	int key[V], parent[V], i, count, neighbour;
	bool sptSet[V];

	for(i = 0; i < V; i++) {
		key[i] = INT_MAX;
		parent[i] = -1;
		sptSet[i] = false;
	}

	key[source] = 0; // Starting Point of Graph. Initialize the distance to 0

	for(count = 0; count < V - 1; count++) {
		int vertex = GetMinKey(key, sptSet); // Get Minimum key value which is not yet included in SPT
		sptSet[vertex] = true; // Include it in SPT
		
		for(neighbour = 0; neighbour < V; neighbour++) {
			if(graph[vertex][neighbour] && !sptSet[neighbour] && key[vertex] + graph[vertex][neighbour] < key[neighbour]) {
				key[neighbour] = key[vertex] + graph[vertex][neighbour];
				parent[neighbour] = vertex;
			}
		}
	}

	PrintSPT(parent, graph, key);
}

void main() {
	int graph[V][V] = 	{{0, 4, 0, 0, 0, 0, 0, 8, 0},
				{4, 0, 8, 0, 0, 0, 0, 11, 0},
				{0, 8, 0, 7, 0, 4, 0, 0, 2},
				{0, 0, 7, 0, 9, 14, 0, 0, 0},
				{0, 0, 0, 9, 0, 10, 0, 0, 0},
				{0, 0, 4, 0, 10, 0, 2, 0, 0},
				{0, 0, 0, 14, 0, 2, 0, 1, 6},
				{8, 11, 0, 0, 0, 0, 1, 0, 7},
				{0, 0, 2, 0, 0, 0, 6, 7, 0}};
	int source = 1;
	// Print the solution
	DijsktraSPT(graph, source); // Dijsktra Shorest Path Tree
}
