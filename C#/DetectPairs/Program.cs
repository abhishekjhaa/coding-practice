using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DetectPairs
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[]{11,2,13,4,15,6};
            var sortedList = array.ToList();
            sortedList.Sort();
            array = sortedList.ToArray();
            int sumToGet = 6;
            DiscoverPairs(array, sumToGet);
        }

        private static void DiscoverPairs(int[] array, int sumToGet)
        {
            int i = 0;
            int j = array.Length - 1;
            while (i < array.Length && j >= 0)
            {
                if (array[i] + array[j] > sumToGet )
                {
                    j--;
                    continue;
                }
                else if (array[i] + array[j] < sumToGet)
                {
                    i++;
                    continue;
                }
                else if (array[i] + array[j] == sumToGet && i != j)
                {
                    Console.WriteLine(array[i] + "+" + array[j] + "=" + sumToGet);
                    i++;
                    j--;
                }
                else if (i == j)
                {
                    i++;
                    j--;
                }
            }

            Console.Read();
            return;
        }
    }
}
