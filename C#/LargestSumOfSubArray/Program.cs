using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LargestSumOfSubArray
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[] { -1, -2 };
            int maxSum = FindMaxSum(array);
            Console.WriteLine(maxSum);
            Console.Read();
        }

        private static int FindMaxSum(int[] array)
        {
            int max = 0;
            int sum = 0;
            int i = 0;
            while (i < array.Length)
            {
                sum += array[i];
                if (sum <= 0)
                {
                    sum = 0;
                }
                else
                {
                    max = sum;
                }

                i++;
            }

            return max;
        }
    }
}
