using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DecimalFractionToBinaryFraction
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = 0.1;
            n += 0.2;
            Console.WriteLine("0.1 + 0.2 = " + n); // 0.30000000000000004
            Console.ReadLine();
        }
    }
}
