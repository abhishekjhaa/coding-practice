using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Rotation
{
    class Program
    {
        static void Main(string[] args)
        {
            var array = new int[] { 1, 2, 2, 2, 2, 2, 2, 2, 3 };
            var rotatedArray = new int[] { 2, 2, 2, 2, 2, 2, 3, 1, 2 };
            int rotatedBy = FindRotation(array, rotatedArray);
            Console.WriteLine(rotatedBy);
            Console.Read();
        }

        private static int FindRotation(int[] array, int[] rotatedArray)
        {
            int i = 0;
            while (i < array.Length - 1)
            {
                if (array[(i + array.Length - 1) / 2] > array[i])
                {
                    i = (i + array.Length - 1) / 2;
                    continue;
                }

                if (rotatedArray[i] > rotatedArray[i + 1])
                    {
                        return array.Length - 1 - i;
                    }
                    else
                    {
                        i++;
                    }
            }

            return 0;
        }
    }
}
