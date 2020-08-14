//From GeeksForGeeks pdf Chapter 24

#include<stdio.h>

#define INF 99999

#define V 4

void Print(int graph[][V]) {
	int i, j;
	for(i = 0; i < V; i++) {
		for(j = 0; j < V; j++) {
			if (graph[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", graph[i][j]);
		}
		printf("\n");
	}
		
}

void FloydWarShall(int graph[][V]) {
	int dist[V][V];
	int i,j,k;
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for(k = 0; k < V; k++)
		for(i = 0; i < V; i++)
                	for(j = 0; j < V; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	Print(dist);
}

void main() {
	int graph[V][V] =      {{0, 5, INF, 10},
				{INF, 0, 3, INF},
				{INF, INF, 0, 1},
				{INF, INF, INF, 0}};

	// Print the solution
	FloydWarShall(graph);
}
