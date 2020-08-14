using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TopologicalSort
{
    public class Graph
    {
        private readonly int vertices;
        private readonly List<int>[] edges; 
        public Graph(int vertices)
        {
            this.vertices = vertices;
            edges = new List<int>[vertices];
            for (int i = 0; i < vertices; i++)
            {
                edges[i] = new List<int>();
            }
        }

        public void AddEdge(int source, int destination)
        {
            edges[source].Add(destination);
        }

        public void TopologicalSort()
        {
            Stack<int> stack = new Stack<int>();
            bool[] visited = new bool[vertices];

            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i])
                    TopologicalSortUtil(i, visited, stack);
            }

            while (stack.Count > 0)
            {
                Console.Write(stack.Pop() + " ");
            }

            Console.ReadLine();
        }

        private void TopologicalSortUtil(int v, bool[] visited, Stack<int> stack)
        {
            visited[v] = true;
            foreach (var edge in edges[v])
            {
                if(!visited[edge])
                    TopologicalSortUtil(edge, visited, stack);
            }

            stack.Push(v);
        }
    }
}
