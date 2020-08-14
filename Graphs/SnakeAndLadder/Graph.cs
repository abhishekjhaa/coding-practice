using System.Collections.Generic;

namespace SnakeAndLadder
{
    public struct QueueEntry
    {
        public int Vertex { get; set; }
        public int DistanceFromSource { get; set; }
    }

    public class Graph
    {
        public static int GetMinimumDiceThrows(int[] moves, int N)
        {
            // The graph has N vertices. Mark all the vertices as not visited
            bool[] visited = new bool[N];

            // Create a queue for BFS
            Queue<QueueEntry> queue = new Queue<QueueEntry>();

            // Enqueue 0 as source
            queue.Enqueue(new QueueEntry{ Vertex = 0, DistanceFromSource = 0});
            visited[0] = true;

            QueueEntry qe = new QueueEntry();
            while (queue.Count > 0)
            {
                qe = queue.Peek();
                int vertex = qe.Vertex;

                // If front vertex is the destination vertex, we are done
                if (vertex == N - 1)
                    break;

                // Otherwise dequeue the front vertex and enqueue its adjacent vertices (or cell numbers reachable through a dice throw)
                queue.Dequeue();
                for (var j = vertex + 1; j <= (vertex + 6) && j < N; ++j)
                {
                    // If this cell is already visited, then ignore
                    if (!visited[j])
                    {
                        // Otherwise calculate its distance and mark it as visited
                        QueueEntry a = new QueueEntry {DistanceFromSource = qe.DistanceFromSource + 1};
                        visited[j] = true;

                        // Check if there a snake or ladder at 'j' then tail of snake or top of ladder become the adjacent of 'i'
                        a.Vertex = moves[j] != -1 ? moves[j] : j;
                        
                        queue.Enqueue(a);
                    }
                }

            }

            // We reach here when 'qe' has last vertex return the distance of vertex in 'qe'
            return qe.DistanceFromSource;
        }
    }
}