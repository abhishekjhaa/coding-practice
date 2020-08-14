using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CycleInAGraph
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

        public bool IsCyclic()
        {
            bool[] visited = new bool[Vertices];
            bool[] recordStack = new bool[Vertices];
            for (int i = 0; i < Vertices; i++)
            {
                if (IsCyclicUtil(i, visited, recordStack))
                    return true;
            }

            return false;
        }

        private bool IsCyclicUtil(int v, bool[] visited, bool[] recordStack)
        {
            if (!visited[v])
            {
                visited[v] = true;
                recordStack[v] = true;
                Console.Write(v + " ");
                var list = adjacentLists[v];
                foreach (int n in list)
                {
                    if (!visited[n] && IsCyclicUtil(n, visited, recordStack))
                    {
                        return true;
                    }
                    else if (recordStack[n])
                    {
                        return true;
                    }
                }
            }

            recordStack[v] = false;
            return false;
        }
    }
}
