using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DebuggerAttribute
{
    class Program
    {
        static void Main(string[] args)
        {
            var lh = new LittleHelp();
            lh.X = 99;
            lh.Y = 15;
            Console.Write(lh.X + " , " + lh.Y);
            Console.ReadLine();
        }
    }
}
