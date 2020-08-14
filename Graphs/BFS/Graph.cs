using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BFS
{
    public class Graph
    {
        public int Vertices { get; private set; }
        private readonly List<int>[] adjacentLists; 
        public Graph(int vertices)
        {
            this.Vertices = vertices;
            adjacentLists = new List<int>[vertices];
            for (int i = 0; i < vertices; i++)
            {
                adjacentLists[i] = new List<int>();
            }
        }

        public void AddEdge(int v, int w)
        {
            adjacentLists[v].Add(w);
        }

        public void BFS(int s)
        {
            bool[] visited = new bool[Vertices];
            var queue = new Queue<int>();
            visited[s] = true;
            queue.Enqueue(s);
            while (queue.Count > 0)
            {
                s = queue.Dequeue();
                Console.Write(s + " ");
                var list = adjacentLists[s];
                foreach (var n in list)
                {
                    if (!visited[n])
                    {
                        visited[n] = true;
                        queue.Enqueue(n);
                    }
                }
            }
        }
    }
}
