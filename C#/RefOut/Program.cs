using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RefOut
{
    class Program
    {
        static void Main(string[] args)
        {
            int i; // not initialized
            replaceOutArg(out i, 99); // no problem!

            int j = 0; // if not initialized
            replaceOutArgRef(ref j, 99); // does not compile!
        }

        private static void replaceOutArg(out int foo, int value)
        {
            // oops - forgot to assign a value to foo! Will get you error.

            foo = value;
        }

        private static void replaceOutArgRef(ref int foo, int value)
        {
            foo = value;
        }
    }
}
