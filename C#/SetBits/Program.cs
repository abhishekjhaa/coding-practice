using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SetBits
{
    using System.Threading;

    class Program
    {
        static void Main(string[] args)
        {
            uint setBit = 37;
            int count = 0;
            for (int i = 0; i < sizeof(int)*8; i++)
            {
                if(((setBit >> i) & 1) == 1)
                    count++;
            }

            Console.WriteLine("Number of Set Bits is : " + count);
            NumberOfSetBits(setBit);
            NumberOfSetBitsEfficient(setBit);
            Console.ReadLine();
        }

        public static uint NumberOfSetBits(uint n)
        {
            uint setbits;
            for (setbits = 0; n > 0; n >>= 1)
            {
                setbits += n & 1;
            }
            Console.WriteLine("NumberOfSetBits is : " + setbits);
            return setbits;
        }

        public static uint NumberOfSetBitsEfficient(uint n)
        {
            uint setbits;
            for (setbits = 0; n > 0; setbits++)
            {
                ////  Doing this will always remove a set bit from the original number. Hence will take minimum steps.
                n &= n - 1;
            }
            Console.WriteLine("NumberOfSetBitsEfficient is : " + setbits);
            return setbits;
        }
    }
}
