using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MinMaxBitOperation
{
    class Program
    {
        static void Main(string[] args)
        {
            const int a = 1;
            int b = -1;
            const int x = int.MaxValue;
            int y = int.MinValue;
            const int width = sizeof(int) * 8;
            Console.WriteLine("{0} (dec)\t\t\t = {1} (bin)", a, Convert.ToString(a, 2).PadLeft(width, '0'));
            Console.WriteLine("{0} (dec)\t\t = {1} (bin)", b, Convert.ToString(b, 2).PadLeft(width, '0'));
            Console.WriteLine("{0} (dec)\t = {1} (bin)", x, Convert.ToString(x, 2).PadLeft(width, '0'));
            Console.WriteLine("{0} (dec)\t = {1} (bin)", y, Convert.ToString(y, 2).PadLeft(width, '0'));
            Console.WriteLine("{0} >> {1} = {2}", a, (width - 1), a >> (width - 1));
            Console.WriteLine("{0} >> {1} = {2}", b, (width - 1), ((uint)b) >> (width - 1));
            Console.WriteLine("{0} >> {1} = {2}", x, (width - 1), x >> (width - 1));
            Console.WriteLine("{0} >> {1} = {2}", y, (width - 1), ((uint)y) >> (width - 1));

            int num1 = 8;
            int num2 = 6;
            int result = BitwiseMinimum.BitwiseMin(num1, num2);
            WriteOnConsole(result, num1, num2);

            num1 = 6;
            num2 = 8;
            result = BitwiseMinimum.BitwiseMinUsingLoop(num1, num2);
            WriteOnConsole(result, num1, num2);

            Console.ReadLine();
        }

        private static void WriteOnConsole(int result, int num1, int num2)
        {
            if (result == num1)
            {
                Console.WriteLine("Number 1 : {0} is less than Number 2 : {1}", num1, num2);
            }
            else
            {
                Console.WriteLine("Number 2 : {0} is less than Number 1 : {1}", num2, num1);
            }
        }
    }
}
