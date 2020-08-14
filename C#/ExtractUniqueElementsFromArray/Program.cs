using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExtractUniqueElementsFromArray
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[]{1,1,1,2,2,3,3,3,12};
            ExtractUnique(array, array.Length);
        }

        private static void ExtractUnique(int[] array, int length)
        {
            int i = 0;
            int j = 1;
            while (i < length && j < length)
            {
                if (array[i] != array[j])
                {
                    Console.WriteLine(array[i].ToString());
                    j++;
                    i = j - 1;
                }
                else if (array[i] == array[j])
                {
                    j++;
                }
            }

            Console.WriteLine(array[i]);
            Console.Read();
        }
    }
}
