//From GeeksForGeeks pdf Chapter 23

#include<stdio.h>
#include<malloc.h>
#include<limits.h>

typedef struct Edge {
	int src;
	int dest;
	int weight;
} Edge;

typedef struct Graph {
	int V; // No of Vertices.
	int E; // No Of Edeges.
	Edge* edge;
} Graph;

Graph* CreateGraph(int V, int E) {
	Graph* graph = malloc(sizeof(Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = malloc(E * sizeof(Edge));
	return graph;
}

void Print(int* vertexArray, int V) {
	int i;
	for(i = 0; i < V; i++) {
		printf("%d \t \t %d\n", i, vertexArray[i]);
	}
}

void BellManFord(Graph* graph, int src) {
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	int i, j;
	for(i = 0; i < V; i++) {
		dist[i] = INT_MAX;
	}
	dist[src] = 0;

	for(i = 1; i < V; i++) {
		for(j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;		
		}
	}

	for(j = 0; j < E; j++) {
		int u = graph->edge[j].src;
                int v = graph->edge[j].dest;
                int weight = graph->edge[j].weight;
                if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                	printf("Graph contains negative weight cycle");
       	}

	Print(dist, V);
}

void main() {
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	Graph* graph = CreateGraph(V, E);
	
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;
	
	// add edge 0-2 (or A-C in above figure)
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;
	
	// add edge 1-2 (or B-C in above figure)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;
	
	// add edge 1-3 (or B-D in above figure)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;
	
	// add edge 1-4 (or A-E in above figure)
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;
	
	// add edge 3-2 (or D-C in above figure)
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;
	
	// add edge 3-1 (or D-B in above figure)
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;
	
	// add edge 4-3 (or E-D in above figure)
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	BellManFord(graph, 0);
}
