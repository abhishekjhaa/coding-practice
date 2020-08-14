using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    public class Singleton4
    {
        /*
         * It is guaranteed that a static constructor in a C# class is called only once at most. If it only creates an
         * instance in the static constructor, there is one instance at most.
         * 
         * Static fields in C# are initialized when the static constructor is called. Since the static constructor is called
         * only once by the .NET runtime, it is guaranteed that only one instance is created even in a multithreading
         * application.
         */

        private Singleton4()
        {
        }
        private static readonly Singleton4 instance = new Singleton4();
        public static Singleton4 Instance
        {
            get
            {
                return instance;
            }
        }
    }
}
