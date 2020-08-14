using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PowerOf2
{
    class Program
    {
        static void Main(string[] args)
        {
            int testNum = 5;
            if (((testNum) & (testNum - 1)) == 0)
            {
                Console.WriteLine(testNum + " is power of 2");
            }
            else
            {
                Console.WriteLine(testNum + " is not power of 2");
            }
            
            Console.Read();
        }
    }
}
