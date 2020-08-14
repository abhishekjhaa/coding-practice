using System;

namespace CycleInAGraph
{
    class Program
    {
        static void Main(string[] args)
        {
            var g = new Graph(4);
            g.AddEdge(0, 1);
            g.AddEdge(0, 2);
            g.AddEdge(1, 2);
            g.AddEdge(2, 0);
            g.AddEdge(2, 3);
            g.AddEdge(3, 3);
            Console.WriteLine(g.IsCyclic() ? "Graph contains cycle" : "Graph doesn't contain cycle");
            Console.ReadLine();
        }
    }
}
