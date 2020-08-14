using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticConstructor
{
    class Program
    {
        static void Main(string[] args)
        {
            B b = new B();
            Console.ReadLine();
        }
    }

    class A
    {
        public A(string text)
        {
            Console.WriteLine(text);
        }
    }

    /*
     * Before any code of the type B gets executed, its static constructor will be invoked first. It initializes 
     * static data fields and then executes statements inside the static constructor. 
     */
    class B
    {
        static A a1 = new A("a1");
        A a2 = new A("a2");
        static B()
        {
            a1 = new A("a3");
        }
        public B()
        {
            a2 = new A("a4");
        }
    }
}

