using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BFS
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

            const int vertex = 1;
            Console.WriteLine("Following is Breadth First Traversal "+ "(starting from vertex {0})", vertex);
            g.BFS(vertex);
            Console.ReadLine();
        }
    }
}
