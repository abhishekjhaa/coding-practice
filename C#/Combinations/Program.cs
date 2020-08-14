using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Combinations
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] str = new char[] { 'a', 'b', 'c' };
            combinations(string.Empty, str, 0); 
            Console.Read();
        }

        private static void combinations(string prefix, char[] array, int index)
        {
            for(int i = index; i < array.Length; i++)
            {
                Console.WriteLine(prefix + array[i]);
            }
            
            if (index < array.Length) 
            { 
                for(int i = index; i < array.Length; i++)
                {
                    combinations(prefix + array[i], array, i+1);
                }
            }
        }
    }
}
