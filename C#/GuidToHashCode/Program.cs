using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GuidToHashCode
{
    public class Program
    {
        static void Main(string[] args)
        {
            Guid x = new Guid("6E50ECCD-E4F3-C1E4-AB01-1253A7C24C4A");
            string y = x.GetAbsoluteHashCode();
            Console.WriteLine(x);
            Console.WriteLine(y);
            Console.ReadLine();
        }
    }
}
