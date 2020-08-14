using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DFS
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph g = new Graph(4);
            g.AddEdge(0, 1);
            g.AddEdge(0, 2);
            g.AddEdge(1, 2);
            g.AddEdge(2, 0);
            g.AddEdge(2, 3);
            g.AddEdge(3, 3);

            const int vertex = 2;
            Console.WriteLine("Following is Depth First Traversal " + "(starting from vertex {0})", vertex);
            g.DFS(vertex);
            Console.ReadLine();
        }
    }
}
