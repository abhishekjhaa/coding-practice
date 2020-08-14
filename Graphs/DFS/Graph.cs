using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DFS
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

        public void DFS(int s)
        {
            bool[] visited = new bool[Vertices];
            DFSUtil(s, visited);
        }

        private void DFSUtil(int v, bool[] visited)
        {
            visited[v] = true;
            Console.Write(v + " ");
            var list = adjacentLists[v];
            foreach (int n in list)
            {
                if (!visited[n])
                {
                    DFSUtil(n, visited);
                }
            }
        }
    }
}
