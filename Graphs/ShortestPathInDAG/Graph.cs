using System;
using System.Collections.Generic;
using System.IO.IsolatedStorage;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShortestPathInDAG
{
    public class AdjacentNode
    {
        private int weight;
        private int vertex;

        public AdjacentNode(int weight, int vertex)
        {
            this.weight = weight;
            this.vertex = vertex;
        }

        public int getWeight()
        {
            return this.weight;
        }

        public int getVertex()
        {
            return this.vertex;
        }
    }

    public class Graph
    {
        private int V;
        private List<AdjacentNode>[] edges;

        public Graph(int V)
        {
            this.V = V;
            this.edges = new List<AdjacentNode>[V];
            for(int i = 0; i < V; i++)
                edges[i] = new List<AdjacentNode>();
        }

        public void AddEdge(int src, int destination, int weight)
        {
            edges[src].Add(new AdjacentNode(weight, destination));
        }

        public void ShortestPath(int src)
        {
            bool[] visited = new bool[V];
            Stack<int> stack = new Stack<int>();
            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
            }

            for (int i = 0; i < V; i++)
            {
                if(!visited[i])
                    TopologicalSortUtil(i, stack, visited);          
            }

            const int INF = 99999;
            int[] dist = new int[V];
            for (int i = 0; i < V; i++)
            {
                dist[i] = INF;
            }
            dist[src] = 0;

            while (stack.Count > 0)
            {
                int u = stack.Pop();
                if (dist[u] != INF)
                    foreach (var node in edges[u])
                    {
                        if (dist[node.getVertex()] > node.getWeight() + dist[u])
                            dist[node.getVertex()] = node.getWeight() + dist[u];
                    }
            }

            for (int i = 0; i < V; i++)
                Console.WriteLine(dist[i] == INF ? "INF " : dist[i].ToString());
            Console.ReadLine();
        }

        private void TopologicalSortUtil(int src, Stack<int> stack, bool[] visited)
        {
            visited[src] = true;
            foreach (var node in edges[src])
            {
                if(!visited[node.getVertex()])
                    TopologicalSortUtil(node.getVertex(), stack, visited);
            }

            stack.Push(src);
        }
    }
}
