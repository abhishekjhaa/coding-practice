using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System;
using System.Collections.Generic;
using System.Diagnostics;
namespace EightQueens
{
    public class Queens
    {
        const int N = 4;
        static readonly int[] queenSquares = new int[N];
        static readonly List<int[]> solutions = new List<int[]>();
        public static void Main(String[] args)
        {
            placeQueen(row: 0);
            int count = 1;
            foreach (int[] solution in solutions)
            {
                Console.WriteLine(string.Format("Solution {0}:", count++));
                printBoard(solution);
                Console.WriteLine();
            }

            Console.ReadKey();
        }
        static bool isNotAttacked(int row, int column)
        {
            /* returns true if the placement of a Q
            * is not attached by any previously placed Q */
            // for all previously placed queens...
            for (int i = 1; i <= row; i++)
            {
                int queencolumn = queenSquares[row - i];
                // same column?
                if (queencolumn == column)
                    return false;
                // same diagonal?
                if (queencolumn == column - i || queencolumn == column + i)
                    return false;
            }

            return true;
        }
        static void placeQueen(int row)
        {
            /* place a Q on a row so that
            * it is not attacked by any other Q */
            // Reached N queens?
            if (row == N)
            {
                solutions.Add((int[])queenSquares.Clone());
                Console.WriteLine("Found a Set \n");
            }
            else
            {
                for (int column = 0; column < N; column++)
                {
                    Console.WriteLine("Checking for {0} , {1}", row, column);
                    if (isNotAttacked(row, column))
                    {
                        queenSquares[row] = column;
                        Console.WriteLine("Found Queens Place on {0} , {1} : But it may change", row, column);
                        placeQueen(row + 1);
                        Console.WriteLine("Found Queens Place on {0} , {1}", row, column);
                    }
                }
            }
        }
        static void printBoard(int[] queenSquares)
        {
            foreach (int queenPosition in queenSquares)
            {
                for (int column = 0; column < queenSquares.Length; column++)
                {
                    Console.Write(queenPosition == column ? "Q " : ". ");
                }

                Console.WriteLine();
            }

            Console.WriteLine();
        }
    }
}
