using System;

namespace SnakeAndLadder
{
    class Program
    {
        static void Main(string[] args)
        {
            // Let us construct the board given in above diagram
            int N = 30; // Board is 6x5 size
            int[] moves = new int[N];
            for (int i = 0; i < N; i++)
                moves[i] = -1;

            // Ladders
            moves[2] = 21; // from 2 we can go to 21 directly
            moves[4] = 7;
            moves[10] = 25;
            moves[19] = 28;

            // Snakes
            moves[26] = 0; // from 26 we come back to 0 directly
            moves[20] = 8;
            moves[16] = 3;
            moves[18] = 6;

            int minMoves = Graph.GetMinimumDiceThrows(moves, N);

            Console.WriteLine(minMoves);

            Console.ReadLine();
        }
    }
}
