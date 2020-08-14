using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BiPartateGraph
{
    class Program
    {
        static void Main(string[] args)
        {
            var g = new Graph(4);
            g.AddEdge(0, 1);
            g.AddEdge(0, 3);
            g.AddEdge(1, 0);
            g.AddEdge(1, 2);
            g.AddEdge(2, 1);
            g.AddEdge(2, 3);
            g.AddEdge(3, 0);
            g.AddEdge(3, 2);
            const int source = 0;
            Console.WriteLine(g.IsBiPartate(source) ? "Graph is BiPartate" : "Graph is not BiPartate");
            Console.ReadLine();
        }
    }
}
