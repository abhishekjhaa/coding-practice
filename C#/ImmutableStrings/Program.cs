using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImmutableStrings
{
    class Program
    {
        static void Main(string[] args)
        {
            Compare();
            Console.ReadLine();
        }

        public static void Compare()
        {
            string a = "prince";
            string b = a;
            Console.WriteLine(string.Format("a == '{0}', b =='{1}'", a, b));
            Console.WriteLine(string.Format("(a == b) == {0}", (a == b)));
            Console.WriteLine("Object.ReferenceEquals(a,b) == " + ReferenceEquals(a, b) + "\n");

            // Now "modify" a, the reference changes!
            a += "ss";
            Console.WriteLine(string.Format("a == '{0}', b =='{1}'", a, b));
            Console.WriteLine(string.Format("(a == b) == {0}", (a == b)));
            Console.WriteLine("Object.ReferenceEquals(a,b) == " + ReferenceEquals(a, b) + "\n");

            // Restore the original value, the original reference returns!
            a = "prince";
            Console.WriteLine(string.Format("a == '{0}', b =='{1}'", a, b));
            Console.WriteLine(string.Format("(a == b) == {0}", (a == b)));
            Console.WriteLine("Object.ReferenceEquals(a,b) == " + ReferenceEquals(a, b) + "\n");
        }
    }
}
