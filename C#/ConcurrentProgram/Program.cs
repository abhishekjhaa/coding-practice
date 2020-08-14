using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConcurrentProgram
{
    using System.Diagnostics;
    using System.Security.Cryptography;
    using System.Threading;

    class Program
    {
        private static Random random = new Random();
        static void Main(string[] args)
        {
            Step1();
            Step2();

            new Thread(Step1).Start();
            new Thread(Step2).Start();

            Thread.Sleep(50*100);
            TestBigSpender.Test();

            Thread.Sleep(50 * 100);
            TestBigSpender.TestWithMultipleThreads();

            if (Debugger.IsAttached) Console.ReadLine();
        }

        private static void Step1()
        {
            for (int i = 0; i < 10; i++)
            {
                Console.Write("One, ");
                Thread.Sleep(random.Next(50));
            }

            Console.WriteLine();
        }

        private static void Step2()
        {
            for (int i = 0; i < 10; i++)
            {
                Console.Write("Two, ");
                Thread.Sleep(random.Next(50));
            }

            Console.WriteLine();
        }
    }
}
