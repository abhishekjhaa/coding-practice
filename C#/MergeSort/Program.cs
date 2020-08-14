using System;

namespace MergeSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arrInts = { 82, 51, 71, 92 };

            //// Check the edge cases.
            if (arrInts == null || arrInts.Length < 1)
            {
                return;
            }

            int length = arrInts.Length;

            //// This is the main call to the function.
            Partition(arrInts, 0, length - 1);

            foreach (var i in arrInts)
            {
                Console.Write(i + ", ");
            }

            Console.Read();
        }

        private static void Partition(int[] arrInts, int start, int end)
        {
            //// Base case for recursion
            if (end - start < 1)
            {
                return;
            }

            int length = end - start + 1;

            //// Getting the middle element
            int middle = start + (length % 2 == 0  ? (length/2) - 1 : length/2);

            //// Dividing the left part of the array
            Partition(arrInts, start, middle);

            //// Dividing the right part of the array
            Partition(arrInts, middle + 1, end);

            //// Sorting the left and right array
            MergeThePartition(arrInts, start, middle, end);


        }

        private static void MergeThePartition(int[] arrInts, int start, int middle, int end)
        {
            int i = start;
            int j = middle + 1;
            int k = start;

            int[] newArrInts = new int[end + 1];

            while (i <= middle && j <= end)
            {
                if (arrInts[i] < arrInts[j])
                {
                    newArrInts[k++] = arrInts[i++];
                }
                else
                {
                    newArrInts[k++] = arrInts[j++];
                }
            }

            while (i <= middle)
            {
                newArrInts[k++] = arrInts[i++];
            }

            while (j <= end)
            {
                newArrInts[k++] = arrInts[j++];
            }

            //// Copying the contents of newArray into originalArray to maintain the consistency.
            for (int l = start; l <= end; l++)
            {
                arrInts[l] = newArrInts[l];
            }
        }
    }
}
