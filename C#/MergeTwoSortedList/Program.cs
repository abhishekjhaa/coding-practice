using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MergeTwoSortedList
{
    class Program
    {
        static void Main(string[] args)
        {
            int?[] array1 = new int?[] { 2, 4, 6, null, null, null };
            int?[] array2 = new int?[] { 1, 3, 5 };
            Merge(array1, array2);
            foreach (var i in array1)
            {
                Console.WriteLine(i);
            }

            Console.Read();
        }

        private static void Merge(int?[] array1, int?[] array2)
        {
            int leftArrayLength = array1.Length - array2.Length - 1;
            int rightArrayLength = array2.Length - 1;
            int totalLength = array1.Length - 1;
            int? temp = 0;

            while (leftArrayLength >= 0 && rightArrayLength >= 0)
            {
                if (array1[leftArrayLength] >= array2[rightArrayLength])
                {
                    array1[totalLength--] = array1[leftArrayLength--];
                }
                else
                {
                    array1[totalLength--] = array2[rightArrayLength--];
                }
            }

            while (leftArrayLength >= 0)
            {
                array1[totalLength--] = array1[leftArrayLength--];
            }

            while (rightArrayLength >= 0)
            {
                array1[totalLength--] = array2[rightArrayLength--];
            }
        }
    }
}
