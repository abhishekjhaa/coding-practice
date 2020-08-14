using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Boggle
{
    class Program
    {
            /*Given a dictionary, a method to do lookup in dictionary and a M x N board
            where every cell has one character. Find all possible words that can be formed
            by a sequence of adjacent charactersNote that we can move to any of 8 adjacent
            characters, but a word should not have multiple instances of same cell.*/

        static HashSet<string> hashSet = new HashSet<string>();

        static void Main(string[] args)
        {
            string[] dictionary = new []{"GEEKS", "FOR", "QUIZ", "GO", "SEEK"};
            
            char[][] x = { new[] {'G', 'I', 'Z'}, new[] {'U', 'E', 'K'}, new[] {'Q', 'S', 'E'} };
            
            //Jagged Array
            char[][] boggle = new char[3][];
            boggle[0] = new char[] {'G', 'I', 'Z'};
            boggle[1] = new char[] {'U', 'E', 'K'};
            boggle[2] = new char[] {'Q','S','E'};

            FindWords(dictionary, boggle);

            Console.ReadLine();
        }

        private static void FindWords(string[] dictionary, char[][] boggle)
        {
            var row = boggle.Length;
            var column = boggle[0].Length;

            bool[][] visited = new bool[row][];
            StringBuilder word = new StringBuilder();
            for (int i = 0; i < row; i++)
            {
                visited[i] = new bool[column]; 
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    DFS(dictionary, boggle, visited, i, j, row, column, word);
                }
            }
        }

        private static void DFS(string[] dictionary, char[][] boggle, bool[][] visited, int i, int j, int ROW, int COLUMN, StringBuilder word)
        {
            if (i < 0 || j < 0 || i >= ROW || j >= COLUMN)
                return;

            if (!visited[i][j])
            {
                visited[i][j] = true;
                word.Append(boggle[i][j]);
                if (dictionary.Contains(word.ToString()) && !hashSet.Contains(word.ToString()))
                {
                        hashSet.Add(word.ToString());
                        Console.WriteLine(word.ToString());
                }

                ////DFS(dictionary, boggle, visited, i + 1, j, ROW, COLUMN, word);
                ////DFS(dictionary, boggle, visited, i, j + 1, ROW, COLUMN, word);
                ////DFS(dictionary, boggle, visited, i + 1, j + 1, ROW, COLUMN, word);
                ////DFS(dictionary, boggle, visited, i - 1, j + 1, ROW, COLUMN, word);
                ////DFS(dictionary, boggle, visited, i - 1, j - 1, ROW, COLUMN, word);
                ////DFS(dictionary, boggle, visited, i + 1, j - 1, ROW, COLUMN, word);
                ////DFS(dictionary, boggle, visited, i, j - 1, ROW, COLUMN, word);
                ////DFS(dictionary, boggle, visited, i - 1, j, ROW, COLUMN, word);

                // Traverse 8 adjacent cells of boggle[i][j]
                for (int row = i - 1; row <= i + 1 && row < ROW; row++)
                    for (int col = j - 1; col <= j + 1 && col < COLUMN; col++)
                        if (row >= 0 && col >= 0 && !visited[row][col])
                            DFS(dictionary, boggle, visited, row, col, ROW, COLUMN, word);

                word.Remove(word.Length - 1, 1);
                visited[i][j] = false;
            }
        }
    }
}
