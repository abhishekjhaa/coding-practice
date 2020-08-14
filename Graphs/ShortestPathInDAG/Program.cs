namespace ShortestPathInDAG
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph g = new Graph(6);
            g.AddEdge(0, 1, 5);
            g.AddEdge(0, 2, 3);
            g.AddEdge(1, 3, 6);
            g.AddEdge(1, 2, 2);
            g.AddEdge(2, 4, 4);
            g.AddEdge(2, 5, 2);
            g.AddEdge(2, 3, 7);
            g.AddEdge(3, 4, -1);
            g.AddEdge(4, 5, -2);
            int s = 1;
            g.ShortestPath(s);
        }
    }
}
