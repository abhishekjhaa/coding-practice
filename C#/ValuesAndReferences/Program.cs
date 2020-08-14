using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ValuesAndReferences
{
    class Program
    {
        static void Main(string[] args)
        {
            var newValue = 100;
            var foo1 = new Foo { Bar = newValue };
            CheckItWorked(newValue, foo1);
            
            // We can change a property of Foo in a method
            newValue = 99;
            replaceFooProperty(foo1, newValue);
            CheckItWorked(newValue, foo1);
            
            // But we can't replace the object itself - this will fail
            newValue = 98;
            replaceFoo(foo1, newValue); // Fails!
            CheckItWorked(newValue, foo1);
            
            // ...unless we pass the object as an explicit
            // reference using the ref keyword
            newValue = 97;
            replaceFoo(ref foo1, newValue);
            CheckItWorked(newValue, foo1);
            Console.ReadLine();
        }
        private static void CheckItWorked(int newValue, Foo foo)
        {
            Console.WriteLine(string.Format("Attempt to change foo.Bar to {0} {1}", newValue, newValue == foo.Bar ? "succeeded" : "**FAILED**"));
        }
        private static void replaceFooProperty(Foo foo, int value)
        {
            // This works
            foo.Bar = value;
        }
        private static void replaceFoo(Foo foo, int value)
        {
            // This doesn't work! The original foo won't be changed
            foo = new Foo { Bar = value };
        }
        private static void replaceFoo(ref Foo foo, int value)
        {
            // This works by replacing the object (only in .NET)
            foo = new Foo { Bar = value };
        }
    }
}
