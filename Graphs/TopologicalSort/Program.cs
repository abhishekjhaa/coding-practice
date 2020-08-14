using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TopologicalSort
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create a graph given in the above diagram
            Graph g = new Graph(6);
            g.AddEdge(5, 2);
            g.AddEdge(5, 0);
            g.AddEdge(4, 0);
            g.AddEdge(4, 1);
            g.AddEdge(2, 3);
            g.AddEdge(3, 1);
 
            Console.WriteLine("Following is a Topological " +
                               "sort of the given graph");
            g.TopologicalSort();
        }
    }
}
