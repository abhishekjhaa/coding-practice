using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace BiPartateGraph
{
    public class Graph
    {
        private readonly int vertices;
        private readonly List<int>[] adjacentLists;
        
        public Graph(int v)
        {
            this.vertices = v;
            this.adjacentLists = new List<int>[v];
            for (int i = 0; i < v; i++)
            {
                adjacentLists[i] = new List<int>();
            }
        }

        public void AddEdge(int source, int destination)
        {
            adjacentLists[source].Add(destination);
        }

        public bool IsBiPartate(int source)
        {
            int[] vertexColor = Enumerable.Repeat(-1, vertices).ToArray(); // -1 for no color, 1 for red, 0 for blue
            Queue<int> queue = new Queue<int>();

            queue.Enqueue(source);
            vertexColor[source] = 1;
            while (queue.Count > 0)
            {
                int parent = queue.Dequeue();
                foreach (var neighbour in adjacentLists[parent])
                {
                    if (vertexColor[neighbour] == -1)
                    {
                        vertexColor[neighbour] = 1 - vertexColor[parent];
                        queue.Enqueue(neighbour);
                    }

                    if (vertexColor[neighbour] == vertexColor[parent])
                        return false;
                }
            }

            return true;
        }
    }
}
