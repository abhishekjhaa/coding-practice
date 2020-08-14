using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimeNumberGenerator
{
    class Program
    {
        static void Main(string[] args)
        {
            var results = Prime.PrimeGenerator(10000);
            foreach (var result in results)
            {
                Console.WriteLine(result);
            }

            Console.ReadLine();
        }
    }
}
