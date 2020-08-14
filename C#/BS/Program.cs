using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BS
{
    class Program
    {
        static void Main(string[] args)
        {
            var x = Console.ReadLine();
            var length = x.ToCharArray().Length;
            int[] array = new int[length];
            int count = 0;
            foreach (var VARIABLE in x.ToCharArray())
            {

                array[count++] = int.Parse(VARIABLE.ToString());
            }

            var end = length-1;
            var numberToSearch = int.Parse(Console.ReadLine());
            int start = 0;
            bool NumberFound = BS(array, numberToSearch , start, end);
            Console.WriteLine(NumberFound);
            Console.Read();

        }

        private static bool BS(int[] c, int numberToSearch, int start, int end)
        {
            int mid = (start + end) / 2;
            if (numberToSearch == c[end] || numberToSearch == c[start] || numberToSearch == c[mid])
            {
                return true;
            }

            if (numberToSearch > c[mid])
            {
                return BS(c, numberToSearch, mid, end);
            }

            return BS(c, numberToSearch, start, mid);
        }
    }
}
