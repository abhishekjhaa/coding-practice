using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MinMaxBitOperation
{
    public static class BitwiseMinimum
    {
        public static int BitwiseMin(int a, int b)
        {
            a -= b;
            a &= a >> (sizeof(int) * 8 - 1);
            return a + b;
        }

        public static int BitwiseMinUsingLoop(int a, int b)
        {
            for (int i = (sizeof(int) * 8 - 1); i > 0; i--)
            {
                //// Console.WriteLine("a is shifted by " + i + " result is : " + (a >> i));
                //// Console.WriteLine("b is shifted by " + i + " result is : " + (b >> i));
                if (a >> i > b >> i) return b;
                else if (a >> i < b >> i) return a;
            }

            return a;
        }
    }
}
