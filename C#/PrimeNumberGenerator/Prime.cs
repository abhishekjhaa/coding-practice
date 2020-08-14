using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimeNumberGenerator
{
    public static class Prime
    {
        private static bool isPrime = true;

        public static int[] PrimeGenerator(int n)
        {
            var primesDiscovered = new int[n];
            for(int i = 0; i < n; i++)
                primesDiscovered[i] = 1;
            primesDiscovered[0] = 2;
            int primeCount = 1;
            for (int j = 3; primesDiscovered[n - 1] == 1; j = j + 2)
            {
                for (int k = 0; k < primeCount; k++)
                {
                    if (j % primesDiscovered[k] == 0)
                    {
                        isPrime = false;
                    }
                }

                if (isPrime)
                {
                    primesDiscovered[primeCount++] = j;
                }

                isPrime = true;
            }

            return primesDiscovered;
        }
    }
}
